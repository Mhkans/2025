#include "framework.h"
#include "Brick.h"
#include "A_ball.h"
Brick::Brick():RectCollider(Vector(0,0) , Vector(80.0f,15.0f))
{
	_brushes.push_back(CreateSolidBrush(PURPLE)); // �Ϲ� ����
	_brushes.push_back(CreateSolidBrush(GOLD)); // �������� ������ ����
	_brushes.push_back(CreateSolidBrush(SILVER)); // �μ� �� ���� ����
}

Brick::~Brick()
{
}

void Brick::Update()
{
	if (!isActive) {
		if (GetItemType() != Brick::Item::NOTHING) {
			//������ ȹ�� ó�� 
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
	//���Ʒ�
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
	//���ʿ�����
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




