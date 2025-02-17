#include "framework.h"
#include "Brick_Item.h"
#include "Item.h"
Brick_Item::Brick_Item()
{
	SetBrickType(Brick::Type::ITEM);
	_item = make_shared<Item>();
	
}
void Brick_Item::Update()
{
	if (!isActive && !_item->canFalling) {
		Vector pos = GetCenter();
		_item->SetCenter(pos);
		_item->canFalling = true;		
	}
	_item->Update();
}

void Brick_Item::Render(HDC hdc)
{
	Brick::Render(hdc);
	_item->Render(hdc);
}



