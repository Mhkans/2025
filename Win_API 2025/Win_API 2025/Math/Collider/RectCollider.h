#pragma once
class RectCollider : public Collider
{
public:
	RectCollider(Vector center, Vector size);
	~RectCollider();

	void Update()override;
	void Render(HDC hdc)override;

	int Left() { return _center.x - _halfSize.x; }
	int Right() { return _center.x + _halfSize.x; }
	int Top() { return _center.y - _halfSize.y; }
	int Bottom() { return _center.y + _halfSize.y; }
	Vector GetHalfSize() { return _halfSize; }
	void SetHalfSize(Vector halfSize) { _halfSize = halfSize; }
	virtual bool IsCollision(shared_ptr<RectCollider> other);
	virtual bool IsCollision(shared_ptr<CircleCollider> other);
	bool IsCollision(const Vector& pos);
private:
	
	Vector _halfSize;

};

