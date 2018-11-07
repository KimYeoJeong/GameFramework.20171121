#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "SDL.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	void getMouseButtonState(int buttonNumber);
private:
	void handleInput();
};
