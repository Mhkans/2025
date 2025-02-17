#pragma once
class Paddle : public RectCollider
{
public:
	Paddle();
	~Paddle();

	void Init();//�ܺο��� ��ü���� ���Ŀ� ����� �Լ�

	void Update()override;
	void Render(HDC hdc)override;

	bool isFired = false;

	vector<shared_ptr<class A_ball>> GetBalls() { return _balls; }
	int GetBallCount() { return _ballCount; }

	void ExtendSkill();
	void DoubleBallSkill();
	void TwoBall_Skill();
private:
	void Input();

	HBRUSH _brush;
	float _speed = 10.0f;

	vector<shared_ptr<class A_ball>> _balls;
	int _ballCount = 10; 
};

