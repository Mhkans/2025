#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_ball = make_shared<CircleCollider>(Vector(0, 0), 10);
	_ballDir = Vector(1, 1).Nomalize();	
}

void Ball::Update()
{
	if (!isActive) {
		_ball->SetCenter(Vector(0, 0));
		SetBallDir(Vector(1, 1).Nomalize());
		_gravity = 0.0f;
		return;
	}
 	_gravity += 0.1f;
	_ball->Update();
	
	if (_ball->GetCenter().x > WIN_WIDTH || _ball->GetCenter().x < 0
		|| _ball->GetCenter().y > WIN_HEIGHT || _ball->GetCenter().y < 0)
	{
		isActive = false;
		
	}

	
	
} 

void Ball::Render(HDC hdc)
{
	if (!isActive) {
		return;
	}
	_ball->Render(hdc);
}


