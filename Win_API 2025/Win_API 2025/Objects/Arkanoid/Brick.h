#pragma once
class Brick : public RectCollider
{
public:
	enum class Type {
		NOMAL,ITEM,WALL
		
	};
	
	Brick();
	virtual ~Brick();

	void Update()override;
	void Render(HDC hdc)override;
	
	bool isActive = true;

	void SetBrickType(Brick::Type type) { _curType = type; }
	Brick::Type GetBrickType() { return _curType; }
	
protected:
	vector<HBRUSH> _brushes;
	Brick::Type _curType = Type::NOMAL;	
};


