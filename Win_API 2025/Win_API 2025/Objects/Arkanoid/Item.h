#pragma once
class Item : public CircleCollider
{
public:
	
	Item();
	~Item();
	enum class ItemType {
		NOTHING, EXTEND_PADDLE, DOUBLE_BALL
	};
	void Update();
	void Render(HDC hdc);

	bool canFalling = false;
	bool isActive = true;

	void SetSkill(function<void(void)> fn) { _skill = fn; }
	void ActiveSkill() { if (_skill) { _skill(); } }
	void SetItemType(int num) { _itemType = static_cast<ItemType>(num); }
	ItemType GetItemType() {return _itemType;}
private:	
	function<void(void)> _skill;
	ItemType _itemType = ItemType::NOTHING;
	Vector _dir = { 0,1 };
	float _speed = 3.0f;
	vector<HBRUSH> _brushes;
};

