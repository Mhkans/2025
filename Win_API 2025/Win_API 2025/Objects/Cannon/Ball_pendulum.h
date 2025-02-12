#pragma once
#include "Ball.h"
class Ball_pendulum : public Ball
{
public:
	// Ball을(를) 통해 상속됨
	void Shoot() override;
private:
	float _deltaTime = 0.0f;
	float _scale = 5.0f;

};

