#pragma once
class ArkanoidScene : public Scene
{
public:
	ArkanoidScene();
	~ArkanoidScene();

	void Update() override;
	void Render(HDC hdc) override;
	
	void GetItem(shared_ptr<class Item> item);
private:
	
	shared_ptr<class Arkanoid> _arkanoid;
	shared_ptr<class Paddle> _paddle;
	shared_ptr<class Arkanoid_UI> _UI;

	int _lifeCount = 5;
	const int& _maxHP = 5;
	bool isDead = false;
};

