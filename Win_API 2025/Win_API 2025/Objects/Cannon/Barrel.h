#pragma once

class Cannon;

class Barrel
{
public:
	Barrel(shared_ptr<CircleCollider> cannonBody); //반드시 캐논에 붙어있어야 생성이된다
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

	//캐논의 정보를 저장 , 배럴이 캐논참조 캐논이 배럴참조 순환해결을 위해 weak로
	//배럴을 만들려면 circleCollider가 있어야한다
	weak_ptr<CircleCollider> _cannonBody; //후처리 대신 캐논에서 circleCollider로 변경 

	float _barrelLength;
	Vector _barrelDir;
	float _angle;
};

