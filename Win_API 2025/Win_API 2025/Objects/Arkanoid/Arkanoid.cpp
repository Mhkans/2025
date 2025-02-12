#include "framework.h"
#include "Arkanoid.h"
#include "A_ball.h"
#include "Brick.h"
#include "Paddle.h"
Arkanoid::Arkanoid()
{
	for (int i = 0; i < _lifeCount; i++) {
		auto life = make_shared<CircleCollider>(Vector((i+1) * 50.0f, 50.0f), 20.0f);
		life->SetGreen();
		_life.push_back(life);
	}
	_paddle = make_shared<Paddle>();
	_ball = make_shared<A_ball>();
	Vector offset = Vector(200.0f,250.0f);
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
	for (auto life : _life) {
		life->Update();
	}
	_paddle->Update();
	_ball->Update();

	if (!_isFired) {
		SetInit();
	}
	if ((GetKeyState(VK_SPACE) & 0x8000) && !_isFired) {
		_ball->isActive = true;
		_isFired = true;
		_ball->SetBallDir(Vector(0, -1));
	}
	if (_ball->GetCenter().y > WIN_HEIGHT) {
		auto Iter = std::find_if(_life.rbegin(), _life.rend(), [](shared_ptr<CircleCollider> circle) {
			return circle->GetColorCount() == 1;
		});
		if (Iter != _life.rend()) {
			(*Iter)->SetRed();
			_lifeCount--;
		}

		_ball->isActive = false;
		_isFired = false;
	}

	for (auto bricks : _bricks) {
		for (auto brick : bricks) {
			if (brick->IsCollisionY(_ball)) {
				brick->isActive = false;
				Vector dir = _ball->GetBallDir();
				_ball->SetBallDir(Vector(dir.x, -dir.y));
				
			}
			if (brick->IsCollisionX(_ball)) {
				brick->isActive = false;
				Vector dir = _ball->GetBallDir();
				_ball->SetBallDir(Vector(-dir.x, dir.y));
				
			}
			
		}
	}
	if (_ball->IsCollision(_paddle) && _isFired) {
		Vector ballCenter = _ball->GetCenter();
		Vector rectCenter = _paddle->GetCenter();
		float length = (ballCenter - rectCenter).Length();
		float ratio = _ball->GetRadius() / length;
		Vector baseV = Vector(1, 0);
		Vector dirV = (ballCenter-rectCenter).Nomalize();
		float angle = atan2(dirV.y, dirV.x);

		Vector shootDir = Vector(cosf(angle) * ratio, -abs(sinf(angle)));

		_ball->SetBallDir(shootDir.Nomalize());

		
		
	}
}

void Arkanoid::Render(HDC hdc)
{
	if (_lifeCount < 1) {
		return;
	}
	for (auto bricks : _bricks) {
		for (auto brick : bricks) {
			brick->Render(hdc);
		}
	}
	for (auto life : _life) {
		life->Render(hdc);
	}
	_paddle->Render(hdc);
	_ball->Render(hdc);

}

void Arkanoid::CreateArkanoid()
{
	for (int y = 0; y < Y_COUNT; y++) {
		for (int x = 0; x < X_COUNT; x++) {
			//안깨지는 블록 세팅
			if (y == Y_COUNT-1 && x % 2 == 0) {
				_bricks[y][x]->SetBrickType(Brick::Type::WALL);
			}
			//아이템을 가진 블록 세팅

		}
	}
}

void Arkanoid::SetItemBricks(const int num)
{
}

void Arkanoid::SetInit()
{
	_ball->SetPos(_paddle->GetCenter() + Vector(0, _ball->GetRadius() * -1.5f));
}
