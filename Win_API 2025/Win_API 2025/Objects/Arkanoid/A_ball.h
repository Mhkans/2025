#pragma once
class A_ball : public CircleCollider
{
public:
	A_ball(shared_ptr<class Paddle> paddle);
	~A_ball();

	void Update()override;
	void Render(HDC hdc)override;

	void SetBallDir(Vector dir) { _ballDir = dir.Nomalize(); }
	Vector GetBallDir() { return _ballDir; }

	bool isFired = false; 
	bool isActive = false;
private:
	void Move();

	weak_ptr<class Paddle> _paddle;
	Vector _ballDir = { 0,0 };
	float _ballSpeed = 10.0f;
	HBRUSH _brush;
};

