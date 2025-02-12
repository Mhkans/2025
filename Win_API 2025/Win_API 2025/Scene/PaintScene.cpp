#include "framework.h"
#include "PaintScene.h"


PaintScene::PaintScene()
{
	_rect = make_shared<RectCollider>(Vector( 0 ,0 ),Vector(50.0f,30.0f));
	_circle = make_shared<CircleCollider>(Vector( 0,0 ), 50.0f);

	_pens.push_back(CreatePen(1, 3, RGB(146, 129, 205)));
	_pens.push_back(CreatePen(1, 3, RGB(255, 163, 75)));

	_brushes.push_back(CreateSolidBrush(RGB(146, 129, 205)));
	_brushes.push_back(CreateSolidBrush(RGB(255, 163, 75)));
}

PaintScene::~PaintScene()
{
	for (auto& pen : _pens) {
		DeleteObject(pen);
	}
	for (auto& brush : _brushes) {
		DeleteObject(brush);
	}
}

void PaintScene::Update()
{
	Vector rectCenter = LERP(_rect->GetCenter(), mousePos, 0.03f);

	_rect->SetCenter(rectCenter);
	_circle->SetCenter(mousePos);

	_rect->Update();
	_circle->Update();
}

void PaintScene::Render(HDC hdc)
{
	SelectObject(hdc, _pens[0]);
	SelectObject(hdc, _brushes[0]);

	_rect->Render(hdc);
	_circle->Render(hdc);
}
