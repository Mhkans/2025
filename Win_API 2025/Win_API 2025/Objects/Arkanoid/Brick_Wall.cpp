#include "framework.h"
#include "Brick_Wall.h"

Brick_Wall::Brick_Wall()
{
	_curType = Brick::Type::WALL;
}

void Brick_Wall::Update()
{
	if (!isActive) {
		isActive = true;
	}
}

void Brick_Wall::Render(HDC hdc)
{
	SelectObject(hdc, _brushes[static_cast<int>(_curType)]);
	RectCollider::Render(hdc);
}
