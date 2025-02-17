#include "framework.h"
#include "Item.h"
#include"Brick_Item.h"

Item::Item() :CircleCollider(Vector(0, 0), 10.0f)
{
	_brushes.push_back(CreateSolidBrush(ORANGE));
	_brushes.push_back(CreateSolidBrush(Light_Purple));	
	Vector pos = GetCenter();
	SetItemType((rand() + (int)pos.x + (int)pos.y) % 2 + 1);
}

Item::~Item()
{
	for (auto brush : _brushes) {
		DeleteObject(brush);
	}
}

void Item::Update()
{
	if (!isActive) {
		return;
	}
	if (canFalling) {
		Vector pos = GetCenter(); 
		SetCenter(pos + _dir * _speed);
	}
	
}

void Item::Render(HDC hdc)
{
	if (!isActive) {
		return;
	}
	CircleCollider::Render(hdc);
	if (_itemType == ItemType::EXTEND_PADDLE) {
		SelectObject(hdc, _brushes[0]);
	}
	else if (_itemType == ItemType::DOUBLE_BALL) {
		SelectObject(hdc, _brushes[1]);
	}

}
