#pragma once
class Arkanoid_UI
{
public:
	Arkanoid_UI(Vector center, Vector size);
	~Arkanoid_UI();

	void Update();
	void Render(HDC hdc);

	void SetValue(float value);

private:
	shared_ptr<RectCollider> _HPbar;
	shared_ptr<RectCollider> _curr;

	HBRUSH _HPBrush;
	HBRUSH _currBrush;
};

