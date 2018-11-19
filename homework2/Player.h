#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include <vector>

class bullet;
class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	std::vector<bullet*> m_bullets;
private:
	void handleInput();
};
