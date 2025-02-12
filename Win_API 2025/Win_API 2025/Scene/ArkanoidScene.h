#pragma once
class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	void Update() override;
	void Render(HDC hdc) override;
	//�������� ����������
	//Ư�������� enum class
private:
	//7 X 3 ������ �ٸ� ������ ��ī���̵� 
	shared_ptr<class Arkanoid> _arkanoid;
	
};

