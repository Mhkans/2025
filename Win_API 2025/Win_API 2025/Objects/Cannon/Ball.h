#pragma once
class Ball
{
public:
	Ball();
	virtual ~Ball() = default;

	void Update();
	void Render(HDC hdc);

	virtual void Shoot() abstract;
	void SetPos(Vector pos) { _ball->SetCenter(pos); }

	bool isActive = false;
	
	void SetBallDir(Vector dir) { _ballDir = dir.Nomalize(); }
	Vector GetBallDir() { return _ballDir; }

	void SetBallSpeed(float value) { _ballSpeed = value; }
	float GetBallSpeed() const { return _ballSpeed; }

	shared_ptr<CircleCollider> GetCollider() { return _ball; }

	const float& GetBallAtk() { return _ballAtk; }
protected:
	shared_ptr<CircleCollider> _ball;
	Vector _ballDir;
	float _ballSpeed = 10.0f;
	
	float _ballAtk = 20.0f;
	float _gravity = 0.0f;
};

