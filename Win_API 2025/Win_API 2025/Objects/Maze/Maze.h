#pragma once
#define MAX_X 25
#define MAX_Y 25
#include "Block.h"
class Maze
{
public:
	struct Edge {
		Vector u; 
		Vector v;
		int cost;
	};

	Maze();
	~Maze();

	void Update();
	void Render(HDC hdc);

	void CreateMaze();
	void CreateMaze_Kruskal();

	Block::Type GetBlockType(Vector pos) { return _blocks[pos.y][pos.x]->GetBlockType(); }
	void SetBlockType(Vector pos , Block::Type type) { _blocks[pos.y][pos.x]->SetBlockType(type); }

	Vector StartPos() { return{ 1,1 }; }
	Vector EndPos() { return{ 23,23 }; }

private:
	vector<vector<shared_ptr<Block>>> _blocks;
	float _blockDistance = 35.0f;
};

