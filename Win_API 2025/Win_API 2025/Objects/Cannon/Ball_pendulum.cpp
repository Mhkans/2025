#include "framework.h"
#include "Ball_pendulum.h"

void Ball_pendulum::Shoot()
{
	_deltaTime += 0.05f;
	Vector xV = Vector(1, 0);
	float dot = _ballDir.Dot(xV);
	float angle = acosf(dot);

	auto baseV = Vector(1, _scale * sinf(_deltaTime));

	float x = baseV.x * cosf(angle) - baseV.y * sinf(angle);
	float y = baseV.y * cosf(angle) + baseV.x * sinf(angle);
	auto newV = Vector(x, y);
	
	_ball->SetCenter(_ball->GetCenter() + newV);
	
}
