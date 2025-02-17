#pragma once
#include"Brick.h"
class Brick_Wall : public Brick
{
public:
	Brick_Wall();

	void Update()override;
	void Render(HDC hdc)override;


private:
	
};

