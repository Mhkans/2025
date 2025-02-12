#pragma once
class Block;
class Maze;

class Player
{
public:
	enum Direction
	{
		UP,
		LEFT,
		DOWN,
		RIGHT,

		DIR_COUNT = 4
	};
	Vector frontPos[8] = {
		{0,-1},
		{-1,0},
		{0,1},
		{1,0},
		{-1,-1},
		{1,1},
		{1,1},
		{-1,1}
	};
	Player(shared_ptr<Maze> maze); //maze 가없다면 플레이어 생성 금지
	~Player();

	void Update();
	
	bool Cango(Vector pos);

	void RightHand();
	void RightHand_stack();
	void BFS(Vector start);
	void DFS(Vector here);
	void Djikstra(Vector start);
	void Astar(Vector start, Vector end);


	struct Vertex_Djikstra {
		Vertex_Djikstra(Vector pos, int cost) : pos(pos), cost(cost) {}
		Vector pos;
		int cost = 0; //시작점부터의 가중치
		bool operator<(const Vertex_Djikstra& v) const
		{
			if (cost < v.cost)
				return true;
			return false;
		}

		bool operator>(const Vertex_Djikstra& v) const
		{
			if (cost > v.cost)
				return true;
			return false;
		}
	};

	struct Vertex {
		Vertex(Vector pos, int g ,int h) : pos(pos), g(g),h(h),f(g+h) {}
		Vector pos;
		int g = 0; 
		int h = 0;
		int f = 0;
		bool operator<(const Vertex& v) const
		{
			if (f < v.f)
				return true;
			return false;
		}

		bool operator>(const Vertex& v) const
		{
			if (f > v.f)
				return true;
			return false;
		}
	};
private:
	
	weak_ptr<Maze> _maze;
	Vector _pos = { 1,1 };
	vector<Vector> _path;
	int _pathIndex = 0;
	float _delayTime = 0.0f;

	Vector _dir = Vector(0, -1);

	vector<vector<bool>> _visited;
	vector<vector<Vector>> _parent;

	vector<vector<int>> _best;
};

