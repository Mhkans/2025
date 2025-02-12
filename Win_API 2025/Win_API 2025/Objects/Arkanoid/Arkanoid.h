#pragma once
#define X_COUNT 11
#define Y_COUNT 5
class Arkanoid
{
public:
	Arkanoid();
	~Arkanoid();

	void Update();
	void Render(HDC hdc);

	void CreateArkanoid();
	void SetItemBricks(const int num);

	void SetInit();
private:
	
private:
	vector<vector<shared_ptr<class Brick>>> _bricks;
	float _xDistance = 160.0f;
	float _yDistance = 25.0f;
	
	shared_ptr<class Paddle> _paddle;
	unordered_map<int, bool> um; //벽돌의 순서 , 아이템블록 지정 여부
	shared_ptr<class A_ball> _ball;

	bool _isFired = false;

	vector<shared_ptr<CircleCollider>> _life;
	int _lifeCount = 3;
	HBRUSH _brush;
};
//알카노이드를 배치하는 클래스
//브릭스가 아이템이면 여기서 정의한 아이템 획득
//벽돌배치 반사처리 -> ball 떨어지면 라이프감소 콜백 패들에 볼 재배치 

//패들에 닿는 위치에 비율을 따라 각도 조절 
