#pragma once
#define X_COUNT 11
#define Y_COUNT 7
class Arkanoid //게임매니저 역할
{
public:
	Arkanoid();
	~Arkanoid();

	void Update();
	void Render(HDC hdc);

	void CreateArkanoid();
	void Init();
	vector<vector<shared_ptr<class Brick>>> GetBricks() { return _bricks; }
	void IsCollision(shared_ptr<class A_ball> ball);
private:
	
private:
	vector<vector<shared_ptr<class Brick>>> _bricks;
	float _xDistance = 160.0f;
	float _yDistance = 30.0f;
	
	bool _isFired = false;
	HBRUSH _brush;
};
