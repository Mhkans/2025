#include "framework.h"
#include "Brick.h"
#include "A_ball.h"
Brick::Brick():RectCollider(Vector(0,0) , Vector(80.0f,15.0f))
{
	_brushes.push_back(CreateSolidBrush(PURPLE)); // 일반 벽돌
	_brushes.push_back(CreateSolidBrush(GOLD)); // 아이템을 보유한 벽돌
	_brushes.push_back(CreateSolidBrush(SILVER)); // 부술 수 없는 벽돌
}

Brick::~Brick()
{
}

void Brick::Update()
{
	if (!isActive) {
		if (GetItemType() != Brick::Item::NOTHING) {
			//아이템 획득 처리 
		}
		SetCenter(Vector(-500, -500));
		return;
	}

}

void Brick::Render(HDC hdc)
{
	if (!isActive) {
		return;
	}
	SelectObject(hdc, _brushes[static_cast<int>(_curType)]);
	RectCollider::Render(hdc);
}

bool Brick::IsCollisionY(shared_ptr<A_ball> other)
{
	//위아래
	Vector dir = (other->GetCenter() - GetCenter());
	Vector baseV = Vector(1, 0);

	if (dir.Length() > (GetHalfSize().Length() + other->GetRadius())) {
		return false;

	}
	float dot = abs(dir.Dot(baseV));
	if (dot > GetHalfSize().x + other->GetRadius()) {
		return false;
	}
	return true;

}

bool Brick::IsCollisionX(shared_ptr<A_ball> other)
{
	//왼쪽오른쪽
	Vector dir = (other->GetCenter() - GetCenter());
	Vector baseV = Vector(0, -1);

	if (dir.Length() > (GetHalfSize().Length() + other->GetRadius())) {
		return false;

	}
	float dot = abs(dir.Dot(baseV));
	if (dot > GetHalfSize().y + other->GetRadius()) {
		return false;
	}
	return true;
	
}




