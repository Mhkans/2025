#include "framework.h"
#include "CannonScene.h"

#include"Objects/Cannon/Cannon.h"

CannonScene::CannonScene()
{
	_cannon1 = make_shared<Cannon>();
	_cannon2 = make_shared<Cannon>();

}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	_cannon1->Update();
	_cannon2->Update();
	
	_timeElipse += 0.1f;

	if (_timeElipse < _delay) {
		return;
	}
	switch (_curTurn)
	{
	case TurnManager::ONE:
	{
		_cannon1->Move();
		_cannon1->Fire(bind(&CannonScene::NextTurn, this));
	}
	break;
	case TurnManager::TWO:
	{
		_cannon2->Move();
		_cannon2->Fire(bind(&CannonScene::NextTurn, this));
	}
	break;
	default:
		break;
	}
	for (auto ball : _cannon1->GetBalls())
	{
		_cannon2->IsCollision(ball);
	}

	for (auto ball : _cannon2->GetBalls())
	{
		_cannon1->IsCollision(ball);
	}
}

void CannonScene::Render(HDC hdc)
{
	_cannon1->Render(hdc);
	_cannon2->Render(hdc);

}

void CannonScene::NextTurn()
{
	int temp = static_cast<int>(_curTurn);
	temp++;
	temp %= static_cast<int>(TurnManager::TURN_COUNT);
	_curTurn = static_cast<TurnManager>(temp);

	_timeElipse = 0.0f;
}
