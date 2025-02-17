#include "framework.h"
#include "Brick.h"

Brick::Brick():RectCollider(Vector(0,0) , Vector(80.0f,15.0f))
{
	_brushes.push_back(CreateSolidBrush(PURPLE)); // �Ϲ� ����
	_brushes.push_back(CreateSolidBrush(GOLD)); // �������� ������ ����
	_brushes.push_back(CreateSolidBrush(SILVER)); // �μ� �� ���� ����
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





