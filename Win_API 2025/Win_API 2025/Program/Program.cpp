#include "framework.h"
#include "Program.h"
#include"Scene/PaintScene.h"
#include<time.h>
#include"Scene/CollisionScene.h"
#include"Scene/LineScene.h"
#include"Scene/LineCollisionScene.h"
#include"Scene/CannonScene.h"
#include"Scene/MazeScene.h"
#include"Scene/ArkanoidScene.h"
HDC Program::backBuffer = nullptr;

Program::Program()
{
	srand(time(nullptr));
	_scene = make_shared<ArkanoidScene>();

	HDC hdc = GetDC(hWnd);
	backBuffer = CreateCompatibleDC(hdc);
	_hBitMap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT); //그림을 그릴 도화지
	SelectObject(backBuffer, _hBitMap);
}

Program::~Program()
{
	DeleteObject(backBuffer);
	DeleteObject(_hBitMap);
}

void Program::Update()
{
	_scene->Update();
}

void Program::Render(HDC hdc)
{
	PatBlt(backBuffer, 0, 0, WIN_WIDTH, WIN_HEIGHT, BLACKNESS);

	_scene->Render(backBuffer);

	BitBlt(hdc, 0, 0, WIN_WIDTH, WIN_HEIGHT, backBuffer, 0, 0, SRCCOPY);//백버퍼에 그린것을 보여주는화면에 복사
}
