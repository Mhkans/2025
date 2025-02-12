#pragma once
class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	void Update() override;
	void Render(HDC hdc) override;
	//떨어지면 라이프감소
	//특수아이템 enum class
private:
	//7 X 3 벽돌과 바를 가지는 알카노이드 
	shared_ptr<class Arkanoid> _arkanoid;
	
};

