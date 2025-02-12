#include "framework.h"
#include "Block.h"

Block::Block() : RectCollider(Vector(0,0), Vector(13.0f,13.0f))
{
	_brushes.push_back(CreateSolidBrush(BLACK)); // none
	_brushes.push_back(CreateSolidBrush(GREEN)); // able
	_brushes.push_back(CreateSolidBrush(RED)); //blocked
	_brushes.push_back(CreateSolidBrush(PURPLE)); //Player
	_brushes.push_back(CreateSolidBrush(ORANGE)); //foot_print
	_brushes.push_back(CreateSolidBrush(Light_Purple)); //serched

	_pens.push_back(CreatePen(1, 3, PURPLE));
	_pens.push_back(CreatePen(1, 3, ORANGE));
	_pens.push_back(CreatePen(1, 3, Light_Purple));
}

Block::~Block()
{
	for (auto brush : _brushes) {
		DeleteObject(brush);
	}
}

void Block::Update()
{
	RectCollider::Update();
}

void Block::Render(HDC hdc)
{
	SelectObject(hdc, _brushes[static_cast<int>(_curType)]);
	_currPen = static_cast<int>(_curType);
	RectCollider::Render(hdc);
}
