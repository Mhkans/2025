#include "framework.h"
#include "CircleCollider.h"
#include "Math/Collider/RectCollider.h"


CircleCollider::CircleCollider(Vector center, float radius):_radius(radius)
{
	_type = Collider::ColType::CIRCLE;
	_center = center;
	
}

CircleCollider::~CircleCollider()
{
	for (auto& pen : _pens) {
		DeleteObject(pen);
	}
}

void CircleCollider::Update()
{
	
}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _pens[_currPen]);
	Ellipse(hdc, _center.x - _radius, _center.y - _radius, _center.x + _radius, _center.y + _radius);

}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other)
{
	Vector circleCenter1 = GetCenter();
	Vector circleCenter2 = other->GetCenter();
	Vector direction = (circleCenter2 - circleCenter1);

	return direction.Length() < _radius + other->_radius;
}
bool CircleCollider::IsCollision(shared_ptr<RectCollider> other)
{
	return other->Collider::IsCollision(shared_from_this());

}
bool CircleCollider::IsCollision(const Vector& pos)
{
	Vector circleCenter = GetCenter();
	Vector direction = pos - circleCenter;

	
	return direction.Length() < _radius;
}
