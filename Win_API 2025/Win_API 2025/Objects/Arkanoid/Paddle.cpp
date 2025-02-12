#include "framework.h"
#include "Paddle.h"

Paddle::Paddle() :RectCollider(CENTER + Vector(0, 500.0f), Vector(100.0f, 10.0f))
{
	_brush = CreateSolidBrush(WHITE);
}

Paddle::~Paddle()
{
}

void Paddle::Update()
{
	if (GetCenter().x + GetHalfSize().x >= WIN_WIDTH) {
		SetCenter(GetCenter() + Vector(-1, 0) * _speed);
		return;
	}
	if(GetCenter().x - GetHalfSize().x <= 0) {
		SetCenter(GetCenter() + Vector(1, 0) * _speed);
		return;
	}
	if (GetKeyState('A') & 0x8000) {
		SetCenter(GetCenter() + Vector(-1, 0) * _speed);
	}
	if (GetKeyState('D') & 0x8000) {
		SetCenter(GetCenter() + Vector(1, 0) * _speed);
	}
}

void Paddle::Render(HDC hdc)
{
	SelectObject(hdc, _brush);
	RectCollider::Render(hdc);
}
