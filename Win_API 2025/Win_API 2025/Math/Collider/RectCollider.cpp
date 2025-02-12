#include "framework.h"
#include "RectCollider.h"


RectCollider::RectCollider(Vector center, Vector size) : _halfSize(size)
{
	_type = Collider::ColType::RECT;
	_center = center;
	
}

RectCollider::~RectCollider()
{
	for (auto& pen : _pens) {
		DeleteObject(pen);
	}
}

void RectCollider::Update()
{

}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_currPen]);
	Rectangle(hdc, _center.x - _halfSize.x, _center.y - _halfSize.y, _center.x + _halfSize.x, _center.y + _halfSize.y);
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other)
{
	float left = (_center.x - _halfSize.x);
	float right = (_center.x + _halfSize.x);
	float top = (_center.y - _halfSize.y);
	float bottom = (_center.y + _halfSize.y);

	float oleft = (other->_center.x - other->_halfSize.x);
	float oright = (other->_center.x + other->_halfSize.x);
	float otop = (other->_center.y - other->_halfSize.y);
	float obottom = (other->_center.y + other->_halfSize.y);


	if (left < oright && oleft < right) {
		if (top < obottom && otop < bottom) {
			return true;
		}
	}

	return false;
}
bool RectCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	Vector dir = (other->GetCenter() - this->GetCenter());
	Vector rightV = Vector(1, 0);
	Vector upV = Vector(0, -1);

	if (dir.Length() > (_halfSize.Length() + other->GetRadius())) {
		return false;
	}
	float lengthX = abs(rightV.Dot(dir));
	if (lengthX > _halfSize.x + other->GetRadius()) {
		return false;
	}
	float lengthY = abs(upV.Dot(dir));
	if (lengthY > _halfSize.y + other->GetRadius()) {
		return false;
	}
	
	return true;

}

bool RectCollider::IsCollision(const Vector& pos)
{
	float hereX = pos.x;
	float hereY = pos.y;
	float left = (_center.x - _halfSize.x);
	float right = (_center.x + _halfSize.x);
	float top = (_center.y - _halfSize.y);
	float bottom = (_center.y + _halfSize.y);

	if (left < hereX && hereX < right) {
		if (top < hereY && hereY < bottom) {
			return true;
		}
	}
	return false;
}
