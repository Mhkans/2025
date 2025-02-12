#pragma once
class CircleCollider :public Collider
{
public:

	CircleCollider(Vector center, float radius);
	~CircleCollider();

	void Update()override;
	void Render(HDC hdc)override;

	float GetRadius() { return _radius; }
	void SetRadius(float radius) { _radius = radius; }

	bool IsCollision(shared_ptr<CircleCollider> other);
	bool IsCollision(shared_ptr<class RectCollider> other);
	bool IsCollision(const Vector& pos);

private:
	
	float _radius;
};

