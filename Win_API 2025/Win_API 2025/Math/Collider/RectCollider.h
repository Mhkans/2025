#pragma once
class RectCollider : public Collider
{
public:
	RectCollider(Vector center, Vector size);
	~RectCollider();

	void Update()override;
	void Render(HDC hdc)override;

	Vector GetHalfSize() { return _halfSize; }

	virtual bool IsCollision(shared_ptr<RectCollider> other);
	virtual bool IsCollision(shared_ptr<CircleCollider> other);
	bool IsCollision(const Vector& pos);
private:
	
	Vector _halfSize;

};

