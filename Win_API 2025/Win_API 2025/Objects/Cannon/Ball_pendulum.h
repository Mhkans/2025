#pragma once
#include "Ball.h"
class Ball_pendulum : public Ball
{
public:
	// Ball��(��) ���� ��ӵ�
	void Shoot() override;
private:
	float _deltaTime = 0.0f;
	float _scale = 5.0f;

};

