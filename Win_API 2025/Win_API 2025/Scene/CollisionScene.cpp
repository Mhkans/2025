#include "framework.h"
#include "CollisionScene.h"

CollisionScene::CollisionScene()
{
	_circle = make_shared<CircleCollider>(Vector(450, 500), 100);
	_movingCircle = make_shared<CircleCollider>(Vector(0, 0), 50);
	_rect = make_shared<RectCollider>(Vector(700, 300), Vector(200,100));
	_movingRect = make_shared<RectCollider>(Vector(0, 0), Vector(50, 50));
	_point = CENTER;
}

CollisionScene::~CollisionScene()
{
}

void CollisionScene::Update()
{
	_movingCircle->SetCenter(mousePos);
	//_movingRect->SetCenter(mousePos);

	_circle->Update();
	_movingCircle->Update();
	_rect->Update();
	_movingRect->Update();

	if (_circle->IsCollision(_movingCircle)) {
		_circle->SetRed();
	}
	else {
		_circle->SetGreen();

	}
	if (_rect->IsCollision(_movingCircle)) {
		_rect->SetRed();
	}
	else {
		_rect->SetGreen();

	}
	if (_movingCircle->IsCollision(_point)) {
		_movingCircle->SetRed();
	}
	else {
		_movingCircle->SetGreen();
	}
	
}

void CollisionScene::Render(HDC hdc)
{
	_circle->Render(hdc);
	_movingCircle->Render(hdc);

	_rect->Render(hdc);
	_movingRect->Render(hdc);
}
