#include "framework.h"
#include "Cannon.h"
#include "Barrel.h"
#include "Ball.h"
#include "Ball_base.h"
#include "Ball_pendulum.h"
#include "Ball_missile.h"

Cannon::Cannon() 
{
	_speed = 5.0f;
	_hp = _maxHp;
	_body = make_shared<CircleCollider>(CENTER, 50);
	//_barrel = make_shared<Barrel>(shared_from_this()); 후처리를 안하면 아직 shared_ptr이 없어서 안됨 
	_barrel = make_shared<Barrel>(_body);
	for (int i = 0; i < _poolCount; i++) {
		shared_ptr<Ball> ball = make_shared<Ball_base>();
		//shared_ptr<Ball> ball = make_shared<Ball_missile>();
		//shared_ptr<Ball> ball = make_shared<Ball_pendulum>();
		_balls.push_back(ball);
	}
	
	
	_hpBar = make_shared<Line>(Vector(0,0), Vector(0,0));
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{	
	if (!_isActive) {
		return;
	}
	_body->Update();
	_hpBar->Update();
	float lineX1 = _body->GetCenter().x - _body->GetRadius();
	float lineX2 = _body->GetCenter().x + _body->GetRadius();
	float lineY = _body->GetCenter().y + _body->GetRadius();

	float ratio = (static_cast<float>(_hp) / _maxHp);
	float endX = _body->GetRadius() * 2 * (ratio); // 체력바가 수치에 상관없이 몸통크기와 같게 만들기

	_hpBar->_start = Vector(lineX1, 5.0f + lineY);
	_hpBar->_end = Vector(lineX1 + ratio * endX, 5.0f + lineY);

	for (int i = 0; i < _poolCount; i++) {
		_balls[i]->Update();

		if (_balls[i]->isActive) {
			auto ball_base = dynamic_pointer_cast<Ball_base>(_balls[i]);
			if (ball_base != nullptr) {
				ball_base->Shoot();
			}

			auto ball_misiile = dynamic_pointer_cast<Ball_missile>(_balls[i]);
			if (ball_misiile != nullptr) {
				ball_misiile->Shoot();
			}

			auto ball_pendulum = dynamic_pointer_cast<Ball_pendulum>(_balls[i]);
			if (ball_pendulum != nullptr) {
				ball_pendulum->Shoot();
			}
		}

	}
	_delay += 0.1f;
	_barrel->Update();
	
}


void Cannon::Render(HDC hdc)
{
	if (!_isActive) {
		return;
	}
	_barrel->Render(hdc);
	_body->Render(hdc);
	for (int i = 0; i < _poolCount; i++) {
		_balls[i]->Render(hdc);
	}
	_hpBar->Render(hdc);
}

void Cannon::Move()
{
	if (GetKeyState('A') & 0x8000) {
		_body->SetCenter(_body->GetCenter() + Vector(-1, 0) * _speed);
	}
	if (GetKeyState('D') & 0x8000) {
		_body->SetCenter(_body->GetCenter() + Vector(1, 0) * _speed);
	}
	if (GetKeyState('S') & 0x8000) {
		_barrel->SetAngle(_barrel->GetAngle() + 0.1f);
	}
	if (GetKeyState('W') & 0x8000) {
		_barrel->SetAngle(_barrel->GetAngle() - 0.1f);
	}
}

void Cannon::Fire(function<void(void)> fn)
{
	if (_isActive == false) return;

	if (_delay < _attackSpeed) {
		return;
	}
	auto Iter = std::find_if(_balls.begin(), _balls.end(), [](const shared_ptr<Ball>& ball) {
		return !(ball->isActive);
	});
	if (Iter == _balls.end()) {
		return;
	}
	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		(*Iter)->SetPos(_barrel->GetMuzzle());
		auto ballDir = _barrel->GetDir();
		(*Iter)->SetBallDir(ballDir);
		(*Iter)->isActive = true;
		_delay = 0.0f;		
		if (fn != nullptr) {
			fn();
		}
	}
}



bool Cannon::IsCollision(shared_ptr<Ball> ball)
{
	if (_body->IsCollision(ball->GetCollider())) {

		ball->isActive = false;
		TakeDamage(ball->GetBallAtk());
		return true;
	}
	return false;
}

void Cannon::TakeDamage(float amount)
{
	_hp -= amount;
	if (_hp <= 0) {
		_isActive = false;
	}
}

