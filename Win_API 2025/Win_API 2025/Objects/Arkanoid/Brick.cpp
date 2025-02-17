#include "framework.h"
#include "Brick.h"

Brick::Brick():RectCollider(Vector(0,0) , Vector(80.0f,15.0f))
{
	_brushes.push_back(CreateSolidBrush(PURPLE)); // 일반 벽돌
	_brushes.push_back(CreateSolidBrush(GOLD)); // 아이템을 보유한 벽돌
	_brushes.push_back(CreateSolidBrush(SILVER)); // 부술 수 없는 벽돌
}

Brick::~Brick()
{
	for (auto brush : _brushes) {
		DeleteObject(brush);
	}
}

void Brick::Update()
{
	if (!isActive) {		
		
		return;
	}

}

void Brick::Render(HDC hdc)
{
	if (!isActive) {
		return;
	}
	SelectObject(hdc, _brushes[static_cast<int>(_curType)]);
	RectCollider::Render(hdc);
}





