#include "framework.h"
#include "Ball_missile.h"

Ball_missile::~Ball_missile()
{
}

bool Ball_missile::IsCollision(Vector point)
{
	return _ball->IsCollision(point);
}

void Ball_missile::Shoot()
{

	if (IsCollision(mousePos)) {
		isActive = false;
	}
	_deltaTime += 0.1f;
	if (_deltaTime >= _delay) {
		auto ballDir = (mousePos - _ball->GetCenter()).Nomalize();
		float cross = _ballDir.Cross(ballDir);
		float dot = _ballDir.Dot(ballDir);
		float angle = std::acosf(dot);
		if (cross < 0) {
			angle -= 0.1f;
		}
		else {
			angle += 0.1f;
		}
		float x = _ballDir.x * cos(angle) - _ballDir.y * sin(angle);
		float y = _ballDir.y * cos(angle) + _ballDir.x * sin(angle);
		_ballDir = Vector(x,y);		
		_ball->SetCenter(_ball->GetCenter() + _ballDir * _ballSpeed);
		_deltaTime = 0.0f;
	}

}
