#include "framework.h"
#include "Player.h"
#include "Maze.h"
#include "Block.h"
Player::Player(shared_ptr<Maze> maze):_maze(maze)
{
	_maze.lock()->SetBlockType(_pos, Block::Type::PLAYER);
	_visited = vector<vector<bool>>(MAX_Y, vector<bool>(MAX_X, false));
	Vector start = _maze.lock()->StartPos();
	Vector end = _maze.lock()->EndPos();
	Astar(start,end);
	
}

Player::~Player()
{
}

void Player::Update()
{
	if (_pathIndex >= _path.size())
	{
		_pathIndex = 0;
		_maze.lock()->CreateMaze_Kruskal();

		_path.clear();

		Vector start = _maze.lock()->StartPos();
		Vector end = _maze.lock()->EndPos();
		
		Astar(start, end);

	}
	
	_delayTime += 0.3f;
	if (_delayTime > 1.0f)
	{
		_delayTime = 0.0f;
		_pos = _path[_pathIndex];

		if (_pathIndex > 0)
		{
			_maze.lock()->SetBlockType(_path[_pathIndex - 1], Block::Type::FOOT_PRINT);
		}
		_maze.lock()->SetBlockType(_pos, Block::Type::PLAYER);

		_pathIndex++;
	}
}

bool Player::Cango(Vector pos)
{
	if (_maze.lock()->GetBlockType(pos) == Block::Type::BLOCKED) {
		return false;
	}
	return true;
}

void Player::RightHand()
{
	//shared_ptr<Maze> maze = _maze.lock();
	Vector pos = _maze.lock()->StartPos();
	Vector endPos = _maze.lock()->EndPos();
	int curDir = Direction::UP;
	
	while (true) {
		if (pos == endPos) {
			break;
		}
		int newDir = (curDir - 1 + DIR_COUNT) % DIR_COUNT;//��ȯ����

		Vector oldVector = pos + frontPos[curDir]; //���� �ٶ󺸰� �ִ� �������� ��ĭ+
		Vector newVector = pos + frontPos[newDir]; //������ �������� ��ĭ+
		
		if (Cango(newVector)) {
			curDir = newDir;
			pos = newVector;
			_path.push_back(pos);
		}
		else if (Cango(oldVector)) {
			pos = oldVector;
			_path.push_back(pos);
		}
		else {
			curDir = (curDir + 1 + DIR_COUNT) % DIR_COUNT;
		}
	}

}

void Player::RightHand_stack() //������ ���� ����Ŭó��
{
	shared_ptr<Maze> maze = _maze.lock();
	Vector pos = maze->StartPos();
	Vector endPos = maze->EndPos();
	int curDir = Direction::UP;

	while (true) {
		if (pos == endPos) {
			break;
		}
		int newDir = (curDir - 1 + DIR_COUNT) % DIR_COUNT;//��ȯ����

		Vector oldVector = pos + frontPos[curDir]; //���� �ٶ󺸰� �ִ� �������� ��ĭ+
		Vector newVector = pos + frontPos[newDir]; //������ �������� ��ĭ+

		if (Cango(newVector)) {
			curDir = newDir;
			pos = newVector;
			_path.push_back(pos);
		}
		else if (Cango(oldVector)) {
			pos = oldVector;
			_path.push_back(pos);
		}
		else {
			curDir = (curDir + 1 + DIR_COUNT) % DIR_COUNT;
		}
	}
	stack<Vector> s;
	for (int i = 0; i < _path.size() - 1; i++) {
		maze->SetBlockType(_path[i], Block::Type::SEARCHED);
		if (!s.empty() && s.top() == _path[i + 1]) {
			s.pop();
		}
		else {
			s.push(_path[i]);
		}
	}
	_path.clear();
	while (true) {
		if (s.empty()) {
			break;
		}
		Vector top = s.top();
		_path.push_back(top);
		s.pop();
	}
	std::reverse(_path.begin(), _path.end());
}

void Player::BFS(Vector start)
{
	queue<Vector> q;
	_parent = vector<vector<Vector>>(MAX_Y, vector<Vector>(MAX_X, Vector(-1,-1)));

	q.push(start);
	_visited[start.y][start.x] = true;
	_parent[start.y][start.x] = start;
	while (true) {
		if (q.empty()) {
			break;
		}
		Vector here = q.front();
		q.pop();
		if (here == _maze.lock()->EndPos()) {
			break;
		}
		

		for (int i = 0; i < 4; i++) {

			Vector there = here + frontPos[i];
			if (here == there) {
				continue;

			}
			if (_visited[there.y][there.x]) {
				continue;

			}
			if (!Cango(there)) {
				continue;
			}
			q.push(there);
			_visited[there.y][there.x] = true;
			_parent[there.y][there.x] = here;
			_maze.lock()->SetBlockType(there, Block::Type::SEARCHED);
		}
	}
	Vector vertex = _maze.lock()->EndPos();
	_path.push_back(vertex);
	while (true)
	{
		// parent�� start�����̸� �׸�
		if (vertex == start)
			break;
		vertex = _parent[vertex.y][vertex.x];
		_path.push_back(vertex);
	}

	std::reverse(_path.begin(), _path.end());
}

void Player::DFS(Vector here)
{
	Vector endPos = _maze.lock()->EndPos();
	_visited[here.y][here.x] = true;
	if (here == endPos) {
		_path.push_back(here);
		return;
	}
	for (int i = 0; i < 4; i++) {
		Vector nextV = here + frontPos[i];
		
		if (here == nextV) {
			continue;
		}
		if (_visited[nextV.y][nextV.x]) {
			continue;
		}
		if (!Cango(nextV)) {
			continue;
		}
		_visited[nextV.y][nextV.y] = true;
		_path.push_back(nextV);
		_maze.lock()->SetBlockType(nextV, Block::Type::SEARCHED);
		DFS(nextV);
	}

	
}

void Player::Djikstra(Vector start)
{
	_parent.resize(MAX_Y, vector<Vector>(MAX_X, Vector(-1, -1)));
	_best.resize(MAX_Y, vector<int>(MAX_X, INT_MAX));
	priority_queue<Vertex_Djikstra, vector<Vertex_Djikstra>, greater<Vertex_Djikstra>> pq;

	_parent[start.y][start.x] = start;
	_best[start.y][start.x] = 0;
	pq.push(Vertex_Djikstra(start, 0));

	while (true) {
		if (pq.empty()) {
			break;
		}
		Vertex_Djikstra hereV = pq.top();
		pq.pop();
		Vector herePos = hereV.pos;
		if (herePos == _maze.lock()->EndPos()) {
			break;
		}

		if (_best[herePos.y][herePos.x] < hereV.cost) {
			continue;
		}
		for (int i = 0; i < 8; i++) {

			Vector nextPos = herePos + frontPos[i];

			if (!Cango(nextPos)) {
				continue;
			}
			int nextCost = 0;
			if (i < 4) {
				nextCost = hereV.cost + 10;
			}
			else{
				nextCost = hereV.cost + 14;
			}

			if (_best[nextPos.y][nextPos.x] < nextCost) {
				continue;
			}

			Vertex_Djikstra nextV(nextPos, nextCost);
			pq.push(nextV);
			_parent[nextPos.y][nextPos.x] = herePos;
			_best[nextPos.y][nextPos.x] = nextCost;
			_maze.lock()->SetBlockType(nextPos, Block::Type::SEARCHED);
		}
		
	}
	Vector vertex = _maze.lock()->EndPos();
	_path.push_back(vertex);
	while (true)
	{
		// parent�� start�����̸� �׸�
		if (vertex == start)
			break;
		vertex = _parent[vertex.y][vertex.x];
		_path.push_back(vertex);
	}

	std::reverse(_path.begin(), _path.end());
}

void Player::Astar(Vector start, Vector end)
{
	_parent = vector<vector<Vector>>(MAX_Y, vector<Vector>(MAX_X, Vector(-1, -1)));
	_best = vector<vector<int>>(MAX_Y, vector<int>(MAX_X, INT_MAX));
	priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;

	_parent[start.y][start.x] = start;
	_best[start.y][start.x] = 0 + start.Manhattan_distance(end) * 10;
	pq.push(Vertex(start, 0, start.Manhattan_distance(end) * 10));

	while (true)
	{
		if (pq.empty())
			break;

		Vertex hereV = pq.top();
		Vector here = hereV.pos;

		// ���� üũ
		if (here == end)
			break;

		pq.pop();

		// ������ �� ���� ��θ� �߰� �� ���� ��
		if (hereV.f > _best[here.y][here.x])
			continue;

		for (int i = 0; i < 8; i++)
		{
			Vector there = here + frontPos[i];

			if (Cango(there) == false)
				continue;

			int thereG = 0;
			// thereCost ã��
			if (i < 4)
				thereG = hereV.g + 10;
			else
				thereG = hereV.g + 14;

			float thereH = there.Manhattan_distance(end) * 10;
			float thereF = thereG + thereH;

			// �� ���� there�� best�� ������ continue;
			if (thereF > _best[there.y][there.x])
				continue;

			Vertex thereV = Vertex(there, thereG, thereH);
			pq.push(thereV);
			_best[there.y][there.x] = thereF;
			_parent[there.y][there.x] = here;
			_maze.lock()->SetBlockType(there, Block::Type::SEARCHED);
		}
	}

	// ������ �������׼� �߰ߵǾ����� Ÿ�� �ö󰡺���
	Vector vertex = _maze.lock()->EndPos();
	_path.push_back(vertex);
	while (true)
	{
		// parent�� start�����̸� �׸�
		if (vertex == start)
			break;
		vertex = _parent[vertex.y][vertex.x];
		_path.push_back(vertex);
	}

	std::reverse(_path.begin(), _path.end());
}

