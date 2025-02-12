#include "framework.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_floor  = make_shared<Line>(Vector(100,600),Vector(1200,500));
	_line1  = make_shared<Line>(Vector(100,100),Vector(100,100));
	_shadow = make_shared<Line>(Vector(100,500),Vector(101,500));
}

LineScene::~LineScene()
{
}

void LineScene::Update()
{
	_floor->Update();
	_line1->Update();
	_shadow->Update();

	_line1->_end = mousePos;


	Vector floorV = (_floor->_end - _floor->_start).Nomalize();
	Vector lineV = (_line1->_end - _line1->_start).Nomalize();
	float shadowLength = (_line1->_end - _line1->_start).Length() * floorV.Dot(lineV);

	_shadow->_end = _shadow->_start + floorV * shadowLength;
	
}

void LineScene::Render(HDC hdc)
{
	_floor->Render(hdc);
	_line1->Render(hdc);
	_shadow->Render(hdc);
}
