#include "framework.h"
#include "Ball_base.h"

Ball_base::~Ball_base()
{
}

void Ball_base::Shoot()
{	
	auto v = _ballDir * _ballSpeed;
	_ball->SetCenter(_ball->GetCenter() + v + Vector(0, _gravity));
}
