#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"
#include "InputHandler.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	Vector2D vec;
	void handleInput();
//private:
//	void handleInput();
};
