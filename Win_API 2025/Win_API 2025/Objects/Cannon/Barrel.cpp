#include "framework.h"
#include "Barrel.h"
#include "Cannon.h"
Barrel::Barrel(shared_ptr<CircleCollider> cannonBody)
{
	_barrelLength = 120.0f;
	_barrelDir = Vector(1, 1).Nomalize();
	_angle = 0;
	_barrel = make_shared<Line>(cannonBody->GetCenter(), cannonBody->GetCenter() + _barrelDir * _barrelLength);

	_cannonBody = cannonBody;

}

Barrel::~Barrel()
{
}

void Barrel::Update()
{
	if (_cannonBody.expired()) {
		return;
	}
	shared_ptr<CircleCollider> cannonBody = _cannonBody.lock();

	_barrel->Update();


	_barrelDir = Vector(cosf(_angle), sinf(_angle));
	_barrel->_start = cannonBody->GetCenter();
	_barrel->_end = cannonBody->GetCenter() + _barrelDir * _barrelLength;

}

void Barrel::Render(HDC hdc)
{
	_barrel->Render(hdc);

}
