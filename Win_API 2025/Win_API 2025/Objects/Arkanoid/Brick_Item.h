#pragma once
#include"Brick.h"
class Brick_Item : public Brick
{
public:
	Brick_Item();	

	void Update()override;
	void Render(HDC hdc)override;

	shared_ptr<class Item> GetItemInfo() { return _item; }
private:
	shared_ptr<class Item> _item;
};

