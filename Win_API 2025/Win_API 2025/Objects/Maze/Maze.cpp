#include "framework.h"
#include "Maze.h"
#include"Block.h"
Maze::Maze()
{
	Vector offset = Vector(600, 200);
	_blocks.resize(MAX_Y);
	for (int y = 0; y < MAX_Y; y++) {
		_blocks[y].reserve(MAX_X);
		for (int x = 0; x < MAX_X; x++) {
			shared_ptr<Block> block = make_shared<Block>();
			Vector pos;
			pos.x = x * _blockDistance;
			pos.y = y * _blockDistance;
			block->SetCenter(pos + offset);
			block->SetBlockType(Block::Type::BLOCKED);
			_blocks[y].push_back(block);
		}
	}
	
	CreateMaze_Kruskal();
}

Maze::~Maze()
{
}

void Maze::Update()
{
	for (auto blockV : _blocks) {
		for (auto block : blockV) {
			block->Update();
		}
	}
}

void Maze::Render(HDC hdc)
{
	for (auto blockV : _blocks) {
		for (auto block : blockV) {
			block->Render(hdc);
		}
	}
}

void Maze::CreateMaze()
{
	
	// 갈 수 있는 노드 만들기
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				_blocks[y][x]->SetBlockType(Block::Type::BLOCKED);
			}
			else
			{
				_blocks[y][x]->SetBlockType(Block::Type::ABLE);
			}
		}
	}

	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			// 시작점 뚫기
			if (x == 1 && y == 1)
			{
				_blocks[y][x]->SetBlockType(Block::Type::ABLE);
			}

			// 끝점 뚫기
			if (x == MAX_X - 2 && y == MAX_Y - 2)
			{
				_blocks[y][x]->SetBlockType(Block::Type::ABLE);
				continue;
			}

			if (x % 2 == 0 || y % 2 == 0)
			{
				continue;
			}

			// 맨 아래길 뚫기
			if (x == MAX_X - 2)
			{
				_blocks[y + 1][x]->SetBlockType(Block::Type::ABLE);
				continue;
			}

			// 맨 오른쪽 뚫기
			if (y == MAX_Y - 2)
			{
				_blocks[y][x + 1]->SetBlockType(Block::Type::ABLE);
				continue;
			}

			// 랜덤하게 아래 혹은 오른쪽으로 길 뚫기
			int randNum = rand() % 2;
			if (randNum == 0)
				_blocks[y + 1][x]->SetBlockType(Block::Type::ABLE);
			else
				_blocks[y][x + 1]->SetBlockType(Block::Type::ABLE);
		}
	}
}

void Maze::CreateMaze_Kruskal()
{
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				_blocks[y][x]->SetBlockType(Block::Type::BLOCKED);
			}
			else
			{
				_blocks[y][x]->SetBlockType(Block::Type::ABLE);
			}
		}
	}

	vector<Edge> edges;
	for (int y = 0; y < MAX_Y; y++) {
		for (int x = 0; x < MAX_X; x++) {
			if (x % 2 == 0 || y % 2 == 0) {
				continue;
			}
			if (x < MAX_X - 2){

				int randCost = rand() % 100;
				Edge edge;
				edge.u = Vector((int)x, (int)y);
				edge.v = Vector((int)x+2, (int)y);
				edge.cost = randCost;
				edges.push_back(edge);
			}
			if (y < MAX_Y - 2) {

				int randCost = rand() % 100;
				Edge edge;
				edge.u = Vector((int)x, (int)y);
				edge.v = Vector((int)x , (int)y+2);
				edge.cost = randCost;
				edges.push_back(edge);
			}
		}
	}
	std::sort(edges.begin(), edges.end(), [](const Edge& a , const Edge& b) {
		return a.cost < b.cost;
	});
	DisjointSet set(MAX_Y * MAX_X);

	for (auto edge : edges) {
		int u = edge.u.y * MAX_X + edge.u.x; //2차원을 1차원으로
		int v = edge.v.y * MAX_X + edge.v.x;

		if (set.FindLeader(u) == set.FindLeader(v)) {
			continue;
		}
		set.Merge(u, v);

		int x = (int)(edge.u.x + edge.v.x) / 2;
		int y = (int)(edge.u.y + edge.v.y) / 2;

		_blocks[y][x]->SetBlockType(Block::Type::ABLE);
	}

}
