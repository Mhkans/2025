#pragma once
class Program
{
public:
	Program();
	~Program();

	void Update();
	void Render(HDC hdc);

	static HDC backBuffer; //화면에 노출되지는 않지만 임시적으로 그림을 그릴 곳
private:
	shared_ptr<Scene> _scene;

	HBITMAP _hBitMap;
};

