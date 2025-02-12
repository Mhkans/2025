#pragma once
class Paddle : public RectCollider
{
public:
	Paddle();
	~Paddle();

	void Update()override;
	void Render(HDC hdc)override;
private:
	HBRUSH _brush;
	float _speed = 10.0f;
};

