#include "framework.h"
#include "Arkanoid_UI.h"

Arkanoid_UI::Arkanoid_UI(Vector center, Vector size)
{
	_HPbar = make_shared<RectCollider>(center, size);
	_curr = make_shared<RectCollider>(center, size);

	_HPBrush = CreateSolidBrush(WHITE);
	_currBrush = CreateSolidBrush(RED);
}
Arkanoid_UI::~Arkanoid_UI()
{
	DeleteObject(_currBrush);
	DeleteObject(_HPBrush);
}

void Arkanoid_UI::Update()
{
	_HPbar->Update();
	_curr->Update();
}

void Arkanoid_UI::Render(HDC hdc)
{
	SelectObject(hdc, _HPBrush);
	_HPbar->Render(hdc);
	SelectObject(hdc, _currBrush);
	_curr->Render(hdc);
}

void Arkanoid_UI::SetValue(float value)
{
	_curr->SetHalfSize(Vector(_HPbar->GetHalfSize().x * value, _curr->GetHalfSize().y));
	float Xdistance = _HPbar->Left() - _curr->Left();
	_curr->SetCenter(_curr->GetCenter() + Vector(Xdistance, 0));
}
