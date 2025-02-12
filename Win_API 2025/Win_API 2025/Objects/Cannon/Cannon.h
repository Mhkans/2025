#pragma once
class Barrel;
class Ball;

class Cannon : public enable_shared_from_this<Cannon>
{
public:
	//friend Barrel; 프렌드써도 괜찮음

	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	shared_ptr<CircleCollider> GetCollider() { return _body; }
	vector<shared_ptr<Ball>> GetBalls() { return _balls; }

	void Move();
	void Fire(function<void(void)> fn);

	bool IsCollision(shared_ptr<Ball> ball);
	void TakeDamage(float amount);
private:
	shared_ptr<CircleCollider> _body;
	//컴포넌트패턴 : 부품처럼 사용
	//장점 : 코드의 재사용성 
	shared_ptr<Barrel> _barrel;

	UINT _poolCount = 30;
	vector<shared_ptr<Ball>> _balls;
	float _speed;

	float _delay = 0.0f;
	const float _attackSpeed = 3.0f;
	
	//전투시스템 
	shared_ptr<Line> _hpBar;
	int _hp;
	const int _maxHp = 120;
	bool _isActive = true;

};

