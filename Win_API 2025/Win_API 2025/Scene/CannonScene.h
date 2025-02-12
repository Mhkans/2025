#pragma once
class Cannon;

class CannonScene : public Scene
{
public:
	enum class TurnManager {

		ONE,
		TWO,
		TURN_COUNT
	};

	CannonScene();
	~CannonScene();

	void Update() override;
	void Render(HDC hdc) override;
	void NextTurn();
private:
	
	shared_ptr<Cannon> _cannon1;
	shared_ptr<Cannon> _cannon2;
	
	TurnManager _curTurn = TurnManager::ONE;
	
	float _delay = 1.0f;
	float _timeElipse = 0.0f;
};

