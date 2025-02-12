#pragma once
class Collider : public enable_shared_from_this<Collider>
{
public:
	enum class ColType
	{
		NONE,
		CIRCLE,
		RECT
	};

	Collider();
	virtual ~Collider() = default;

	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;

	bool IsCollision(shared_ptr<Collider> other);

	virtual bool IsCollision(const Vector& pos) abstract;
	virtual bool IsCollision(shared_ptr<class CircleCollider> other)abstract;
	virtual bool IsCollision(shared_ptr<class RectCollider> rect)abstract;

	Vector GetCenter() { return _center; }
	void SetCenter(const Vector& pos) { _center = pos; }

	void SetGreen() { _currPen = 1; }
	void SetRed() { _currPen = 2; }

	UINT GetColorCount() { return _currPen; }

protected:
	vector<HPEN> _pens;
	UINT _currPen = 0;
	Vector _center;
	ColType	_type = ColType::NONE;
};

