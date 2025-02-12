#pragma once

class Cannon;

class Barrel
{
public:
	Barrel(shared_ptr<CircleCollider> cannonBody); //�ݵ�� ĳ�� �پ��־�� �����̵ȴ�
	~Barrel();

	void Update();
	void Render(HDC hdc);

	void SetDirection(Vector dir) { _barrelDir = dir.Nomalize(); }
	void SetAngle(float angle) { _angle = angle; }

	Vector GetDir() { return _barrelDir; }
	float GetAngle() { return _angle; }
	Vector GetMuzzle() { return _barrel->_end; }


private:
	shared_ptr<Line> _barrel;

	//ĳ���� ������ ���� , �跲�� ĳ������ ĳ���� �跲���� ��ȯ�ذ��� ���� weak��
	//�跲�� ������� circleCollider�� �־���Ѵ�
	weak_ptr<CircleCollider> _cannonBody; //��ó�� ��� ĳ���� circleCollider�� ���� 

	float _barrelLength;
	Vector _barrelDir;
	float _angle;
};

