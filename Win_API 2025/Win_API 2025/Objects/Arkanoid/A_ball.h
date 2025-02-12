#pragma once
class A_ball : public CircleCollider
{
public:
	A_ball();
	~A_ball();

	void Update()override;
	void Render(HDC hdc)override;

	void SetPos(Vector pos) { SetCenter(pos); }
	void SetBallDir(Vector dir) { _ballDir = dir.Nomalize(); }
	Vector GetBallDir() { return _ballDir; }

	void Move();

	bool isActive = false;
private:
	Vector _ballDir = { 0,0 };
	float _ballSpeed = 13.0f;
	HBRUSH _brush;
};
//공 무빙까지만 
