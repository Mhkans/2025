#pragma once
class LineCollisionScene:public Scene
{
public:
	LineCollisionScene();
	~LineCollisionScene();

	void Update() override;
	void Render(HDC hdc) override;

	
private:
	shared_ptr<Line> _line1;
	shared_ptr<Line> _line2;
	shared_ptr<Collider> _hitPoint;
};

