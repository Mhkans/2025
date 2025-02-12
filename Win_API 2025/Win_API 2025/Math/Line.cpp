#include "framework.h"
#include "Line.h"

Line::Line(Vector start, Vector end) :_start(start), _end(end)
{
	HPEN _pen1 = CreatePen(1, 3, PURPLE);
	HPEN _pen2 = CreatePen(1, 3, RED);
	
	_pen.push_back(_pen1);
	_pen.push_back(_pen2);
}

Line::~Line()
{
	for (auto& pen : _pen) {
		DeleteObject(pen);
	}
}

void Line::Update()
{
	
}

void Line::Render(HDC hdc)
{
	SelectObject(hdc,_pen[_currPen]);
	MoveToEx(hdc, _start.x, _start.y, nullptr);
	LineTo(hdc, _end.x, _end.y);
}

Line::HitResult Line::IsCollision(shared_ptr<Line> other)
{
	Line::HitResult hitResult;
	Vector line1V = (_end - _start);
	Vector line2V = (other->_end - other->_start);

	Vector cross1 = (_start - other->_start);
	Vector cross2 = (_end - other->_start);

	Vector crossV1 = (other->_start - _start);
	Vector crossV2 = (other->_end - _start);

	float check1 = line1V.Cross(crossV1) * line1V.Cross(crossV2);
	float check2 = line2V.Cross(cross1) * line2V.Cross(cross2);

	float triangle1 = line2V.Cross(cross2);
	float triangle2 = cross1.Cross(line2V);

	hitResult.IsCollision = check1 < 0 && check2 < 0;

	if (!hitResult.IsCollision) {
		return hitResult;
	}
	else {
		//충돌했을경우
		Vector length = line1V*(triangle2 / (triangle1 + triangle2));
		hitResult.hitPoint = _start + length;
	}

	return hitResult;

}
