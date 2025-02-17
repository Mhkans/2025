#include "framework.h"
#include "Arkanoid.h"
#include "A_ball.h"
#include "Brick.h"
#include "Brick_Item.h"
#include "Brick_Wall.h"
#include "Paddle.h"
#include "Item.h"
Arkanoid::Arkanoid()
{
	Vector offset = Vector(200.0f,200.0f);
	_bricks.resize(Y_COUNT);
	for (int y = 0; y < Y_COUNT; y++) {
		_bricks[y].reserve(X_COUNT);
		for (int x = 0; x < X_COUNT; x++) {
			shared_ptr<Brick> brick = make_shared<Brick>();
			Vector pos;
			pos.x = x * _xDistance;
			pos.y = y * _yDistance;
			brick->SetCenter(pos + offset);
			brick->SetBrickType(Brick::Type::NOMAL);
			_bricks[y].push_back(brick);
		}
	}
	
	CreateArkanoid();
}

Arkanoid::~Arkanoid()
{
}

void Arkanoid::Update()
{
	for (auto bricks : _bricks) {
		for (auto brick : bricks) {
			brick->Update();
		}
	}
	
}

void Arkanoid::Render(HDC hdc)
{	
	for (auto bricks : _bricks) {
		for (auto brick : bricks) {
			brick->Render(hdc);
		}
	}
}

void Arkanoid::CreateArkanoid()
{
	for (int y = 0; y < Y_COUNT; y++) {
		for (int x = 0; x < X_COUNT; x++) {		
			//부술 수 없는 블록 세팅
			if (y == Y_COUNT - 1 && x % 2 == 0) {
				shared_ptr<Brick> wallBrick = make_shared<Brick_Wall>();
				Vector pos = _bricks[y][x]->GetCenter();
				wallBrick->SetCenter(pos);
				_bricks[y][x] = wallBrick;

			}
			//아이템을 가진 블록 세팅
			if (y == Y_COUNT - 1 && x % 2 == 1) {
				shared_ptr<Brick_Item> itemBrick = make_shared<Brick_Item>();
				Vector pos = _bricks[y][x]->GetCenter();
				itemBrick->SetCenter(pos);					
				_bricks[y][x] = itemBrick;
				
			}
			if (y == 0) {
				shared_ptr<Brick_Item> itemBrick = make_shared<Brick_Item>();
				Vector pos = _bricks[y][x]->GetCenter();
				itemBrick->SetCenter(pos);
				_bricks[y][x] = itemBrick;
			}

		}
	}
}


void Arkanoid::Init()
{

}

void Arkanoid::IsCollision(shared_ptr<class A_ball> ball)
{
	for (auto bricks : _bricks)
	{
		for (auto brick : bricks)
		{
			if (!brick->isActive) {
				continue;
			}

			if (!brick->IsCollision(ball)) {
				continue;
			}

			
			if (ball->GetCenter().x < brick->Right() && ball->GetCenter().x > brick->Left()){
			
				Vector dir = ball->GetBallDir();
				dir.y *= -1.0f;

				ball->SetBallDir(dir);
			}
			else if(ball->GetCenter().y <brick->Bottom() && ball->GetCenter().y>brick->Top()){

				Vector dir = ball->GetBallDir();
				dir.x *= -1.0f;

				ball->SetBallDir(dir);
			}
			if (brick->GetBrickType() != Brick::Type::WALL) {
				brick->isActive = false;
			}
		}
	}
}
