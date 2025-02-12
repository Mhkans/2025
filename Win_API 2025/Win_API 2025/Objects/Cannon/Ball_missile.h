#pragma once

#include "Ball.h"
class Ball_missile : public Ball
{
public:
	~Ball_missile();	
	// Ball을(를) 통해 상속됨
	void Shoot() override;
private:
	bool IsCollision(Vector point);
	const float _delay = 0.5f;
	float _deltaTime = 0.0f;
};

