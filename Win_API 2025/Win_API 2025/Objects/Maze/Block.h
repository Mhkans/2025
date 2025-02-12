#pragma once
class Block : public RectCollider
{
public:
	enum class Type {
		NONE,ABLE,BLOCKED,PLAYER,FOOT_PRINT,SEARCHED,TYPE_COUNT
	};
	Block();
	~Block();

	void Update()override;
	void Render(HDC hdc)override;

	void SetBlockType(Block::Type type) { _curType = type; }
	Block::Type GetBlockType() { return _curType; }
private:
	vector<HBRUSH> _brushes;
	Block::Type _curType = Type::NONE;
};

