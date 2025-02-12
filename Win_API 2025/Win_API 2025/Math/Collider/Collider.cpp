#include "framework.h"
#include "Collider.h"
#include "RectCollider.h"
#include"CircleCollider.h"
Collider::Collider()
{
	_pens.push_back(CreatePen(1, 3, BLACK));
	_pens.push_back(CreatePen(1, 3, GREEN));
	_pens.push_back(CreatePen(1, 3, RED));
}

bool Collider::IsCollision(shared_ptr<Collider> other)
{
	ColType otherType = other->_type;

	switch (otherType)
	{
	case Collider::ColType::NONE:
		break;
	case Collider::ColType::CIRCLE:
		return IsCollision(static_pointer_cast<CircleCollider>(other));
		break;
	case Collider::ColType::RECT:
		return IsCollision(static_pointer_cast<RectCollider>(other));
		break;
	
	default:
		break;
	}

	return false;
}

bool Collider::IsCollision(const Vector& pos)
{
	switch (shared_from_this()->_type)
	{
	case Collider::ColType::NONE:
		break;
	case Collider::ColType::CIRCLE:
	{
		auto circle = static_pointer_cast<CircleCollider>(shared_from_this());

		return circle->IsCollision(pos);
	}
	break;
	case Collider::ColType::RECT:
	{
		auto rect = static_pointer_cast<RectCollider>(shared_from_this());

		return rect->IsCollision(pos);
	}
	break;
	default:
		break;
	}

	return false;
}
