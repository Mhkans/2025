#include "framework.h"
#include "LineCollisionScene.h"

LineCollisionScene::LineCollisionScene()
{
	_line1 = make_shared<Line>(Vector(500,100),Vector(100,100));
	_line2 = make_shared<Line>(Vector(500,500),Vector(1200,200));

	_hitPoint = make_shared<CircleCollider>(Vector(0,0), 10.0f);
	
}

LineCollisionScene::~LineCollisionScene()
{
}

void LineCollisionScene::Update()
{
	_line1->Update();
	_line2->Update();

	_line1->_end = mousePos;

	if (_line2->IsCollision(_line1).IsCollision) {
		_hitPoint->SetCenter(_line2->IsCollision(_line1).hitPoint);
		_line1->SetRed();
		_line2->SetRed(); 
	}
	else {
		_hitPoint->SetCenter(Vector(0, 0));
		_line1->SetPurple();
		_line2->SetPurple();
	}


}

void LineCollisionScene::Render(HDC hdc)
{
	_line1->Render(hdc);
	_line2->Render(hdc);
	_hitPoint->Render(hdc);
}

