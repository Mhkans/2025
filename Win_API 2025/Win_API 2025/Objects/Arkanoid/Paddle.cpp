#include "framework.h"
#include "Paddle.h"
#include "A_ball.h"
Paddle::Paddle() :RectCollider(CENTER + Vector(0, 500.0f), Vector(100.0f, 10.0f))
{
	_brush = CreateSolidBrush(WHITE);	
}

Paddle::~Paddle()
{
}

void Paddle::Init()
{
	for (int i = 0; i < _ballCount; i++) {
		
		shared_ptr<A_ball> ball = make_shared<A_ball>(dynamic_pointer_cast<Paddle>(shared_from_this()));
		_balls.push_back(ball);
	}
	_balls[0]->isActive = true;
}

void Paddle::Update()
{
	for (auto ball : _balls) {
		ball->Update();		
	}
	Input();
	auto Iter = std::find_if(_balls.begin(), _balls.end(), [](shared_ptr<A_ball> a)-> bool
	{
		return a->isActive;
	});
	if (Iter == _balls.end()) {
		_balls[0]->isActive = true;
		_balls[0]->isFired = false;
		isFired = false;
	}	
	
}

void Paddle::Render(HDC hdc)
{
	for (auto ball : _balls) {
		ball->Render(hdc);
	}
	SelectObject(hdc, _brush);
	RectCollider::Render(hdc);
}

void Paddle::ExtendSkill()
{
	Vector temp = GetHalfSize();
	SetHalfSize(temp * 1.1f);	
}

void Paddle::DoubleBallSkill()
{
	auto Iter = std::find_if(_balls.begin(), _balls.end(), [](shared_ptr<A_ball> a)-> bool
	{
		return !a->isFired &&!a->isActive;
	});
	if (Iter != _balls.end()) {
		(*Iter)->isFired = true;
		(*Iter)->isActive = true;	
		(*Iter)->SetBallDir(Vector(rand()%5+1, rand() % 5 + 1).Nomalize());
	}
	else {
		return;
	}
}

void Paddle::TwoBall_Skill()
{
	auto Iter = std::find_if(_balls.begin(), _balls.end(), [](shared_ptr<A_ball> a)-> bool
	{
		return !a->isActive && !a->isFired;
	});
	if (Iter != _balls.end()) {
		(*Iter)->isActive = true;
		isFired = false;
	}
	
}

void Paddle::Input()
{
	if (GetCenter().x + GetHalfSize().x >= WIN_WIDTH) {
		SetCenter(GetCenter() + Vector(-1, 0) * _speed);
		return;
	}
	if (GetCenter().x - GetHalfSize().x <= 0) {
		SetCenter(GetCenter() + Vector(1, 0) * _speed);
		return;
	}
	if (GetKeyState('A') & 0x8000) {
		SetCenter(GetCenter() + Vector(-1, 0) * _speed);
	}
	if (GetKeyState('D') & 0x8000) {
		SetCenter(GetCenter() + Vector(1, 0) * _speed);
	}	
	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		if (isFired) {
			return;
		}
		
		auto Iter = std::find_if(_balls.begin(), _balls.end(), [](shared_ptr<A_ball> a)-> bool
		{
			return !a->isFired;
		});
		if (Iter != _balls.end()) {			
			(*Iter)->SetBallDir(Vector(0, -1));
			(*Iter)->isFired = true;
		}
	}
}
