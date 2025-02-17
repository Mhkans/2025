#include "framework.h"
#include "A_ball.h"
#include"Paddle.h"
A_ball::A_ball(shared_ptr<class Paddle> paddle) : CircleCollider(Vector(-500, -500), 25.0f)
{
	_brush = CreateSolidBrush(WHITE);
	_paddle = paddle;
}

A_ball::~A_ball()
{
}

void A_ball::Update()
{
	Move();
	if (!isActive || _paddle.expired()) {
		return;
	}

	shared_ptr<Paddle> paddle = _paddle.lock();
	if (!isFired) {
		SetCenter(paddle->GetCenter() + Vector(0, -GetRadius()));
	}
	//벽면 충돌 처리
	if (GetCenter().x >= WIN_WIDTH || GetCenter().x <= 0)
	{
		_ballDir.x *= -1;

	}
	if (GetCenter().y <= 0) {

		_ballDir.y *= -1;
	}
	if (GetCenter().y >= WIN_HEIGHT) {
		isActive = false;
	}
	
	if (IsCollision(paddle)) {
		Vector dir =  GetCenter()- paddle->GetCenter();
		SetBallDir(dir);
	}
	
}

void A_ball::Render(HDC hdc)
{
	if (!isActive) {
		return;
	}
	SelectObject(hdc, _brush);
	CircleCollider::Render(hdc);
}

void A_ball::Move()
{
	SetCenter(GetCenter() + _ballDir * _ballSpeed);
}
