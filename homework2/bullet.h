#pragma once
#include <map>
#include "GameObject.h"
#include "LoaderParams.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Wall.h"


class bullet : public SDLGameObject
{
public:
	bullet(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	bool isCollide = false;
	Wall* wall_break;// 
private:
	const int boxPosX[2] = { 450, 650 };
	const int boxPosY[2] = { 50, 250 };
};