#include "framework.h"
#include "ArkanoidScene.h"
#include "Objects/Arkanoid/A_ball.h"
#include "Objects/Arkanoid/Brick.h"
#include "Objects/Arkanoid/Brick_Item.h"
#include "Objects/Arkanoid/Item.h"
#include "Objects/Arkanoid/Paddle.h"
#include "Objects/Arkanoid/Arkanoid.h"
#include "Objects/Arkanoid/Arkanoid_UI.h"
ArkanoidScene::ArkanoidScene()
{
	_arkanoid = make_shared<Arkanoid>();
	_paddle = make_shared<Paddle>();
	_UI = make_shared<Arkanoid_UI>(CENTER + Vector(-750.0f, -700.0f), Vector(200.0f, 20));

	_paddle->Init();
	_UI->SetValue(1);
}

ArkanoidScene::~ArkanoidScene()
{
}

void ArkanoidScene::Update()
{
	_arkanoid->Update();
	_paddle->Update();
	_UI->Update();
	auto balls = _paddle->GetBalls();
	float ratio = static_cast<float>(_lifeCount) / _maxHP;
	_UI->SetValue(ratio);
	for (auto ball : balls)
	{
		if (ball->isFired) {
			_arkanoid->IsCollision(ball);
		}
		
	}
	for (auto bricks : _arkanoid->GetBricks()) {
		for (auto brick : bricks) {
			shared_ptr<Brick_Item> item = dynamic_pointer_cast<Brick_Item>(brick);
			if (item == nullptr) {
				continue;
			}
			if (item->GetItemInfo()->GetItemType() == Item::ItemType::EXTEND_PADDLE) {
				item->GetItemInfo()->SetSkill(bind(&Paddle::ExtendSkill, _paddle));
			}
			if (item->GetItemInfo()->GetItemType() == Item::ItemType::DOUBLE_BALL) {
				item->GetItemInfo()->SetSkill(bind(&Paddle::TwoBall_Skill, _paddle));

			}
			
			GetItem(item->GetItemInfo());

		}
	}
	auto Iter = std::find_if(balls.begin(), balls.end(), [](shared_ptr<A_ball>& a) {
		return !a->isFired && !a->isActive;
	});
	if (Iter == balls.end()) {
		_lifeCount--;
	}
}

void ArkanoidScene::Render(HDC hdc)
{
	_arkanoid->Render(hdc);
	_paddle->Render(hdc);

	_UI->Render(hdc);
}

void ArkanoidScene::GetItem(shared_ptr<class Item> item)
{	
	if (_paddle->IsCollision(item) && item->isActive) {		
		item->ActiveSkill();
		item->isActive = false;		
	}
}
