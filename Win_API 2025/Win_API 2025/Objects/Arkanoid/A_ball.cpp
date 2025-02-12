#include "framework.h"
#include "A_ball.h"

A_ball::A_ball() : CircleCollider(Vector(0, 0),25.0f)
{
	_brush = CreateSolidBrush(WHITE);
}

A_ball::~A_ball()
{
}

void A_ball::Update()
{
	Move();
	if (!isActive) {
		return;
	}
	
	//벽면 충돌 처리
	if (GetCenter().x >= WIN_WIDTH || GetCenter().x <= 0)
	{
		_ballDir.x *= -1;

	}
	if (GetCenter().y <= 0) {

		_ballDir.y *= -1;
	}

}

void A_ball::Render(HDC hdc)
{
	SelectObject(hdc, _brush);
	CircleCollider::Render(hdc);
}

void A_ball::Move()
{
	SetCenter(GetCenter() + _ballDir * _ballSpeed);
}
