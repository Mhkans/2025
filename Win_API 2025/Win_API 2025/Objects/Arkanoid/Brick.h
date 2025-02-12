#pragma once
class Brick : public RectCollider
{
public:
	enum class Type {
		NOMAL,ITEM,WALL
		
	};
	enum class Item {
		NOTHING ,FIRST,SECOND
	};
	Brick();
	~Brick();

	void Update()override;
	void Render(HDC hdc)override;

	bool IsCollisionY(shared_ptr<class A_ball> other);
	bool IsCollisionX(shared_ptr<class A_ball> other);
	bool isActive = true;

	void SetBrickType(Brick::Type type) { _curType = type; }
	Brick::Type GetBrickType() { return _curType; }
	void SetItemType(Brick::Item item) { _curItem = item; }
	Brick::Item GetItemType() { return _curItem; }
private:
	vector<HBRUSH> _brushes;
	Brick::Type _curType = Type::NOMAL;
	Brick::Item _curItem = Item::NOTHING;


};


