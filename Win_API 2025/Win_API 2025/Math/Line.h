#pragma once
class Line
{
public:
	struct HitResult {

		bool IsCollision = false;
		Vector hitPoint = Vector(0,0);
	};

	Line(Vector start, Vector end);
	~Line();

	void Update();
	void Render(HDC hdc);

	HitResult IsCollision(shared_ptr<Line> other);
	void SetCircleCenter(Vector pos) { _circleCenter = pos; }
	Vector GetCircleCenter() { return _circleCenter; }

	void SetPurple() { _currPen = 0; }
	void SetRed() { _currPen = 1; }
public:
	Vector _start;
	Vector _end;

private:
	vector<HPEN> _pen;
	UINT _currPen = 0;
	Vector _circleCenter;
};

