#pragma once
#include"Math/Vector.h"

#define PI 3.141592
#define LERP(s,e,t) s + (e-s)*t

#define RED		RGB(255,0,0)
#define GREEN	RGB(0,255,0)
#define BLUE	RGB(0,0,255)
#define WHITE	RGB(255,255,255)
#define BLACK	RGB(0,0,0)
#define PURPLE	RGB(105, 0, 130)
#define Light_Purple	RGB(230, 200, 230)
#define ORANGE	RGB(255, 163, 75)
#define SILVER	RGB(184, 184, 178)
#define GOLD	RGB(255, 215, 0)

#define WIN_WIDTH 2000
#define WIN_HEIGHT 1500
#define CENTER Vector(WIN_WIDTH,WIN_HEIGHT) * 0.5f