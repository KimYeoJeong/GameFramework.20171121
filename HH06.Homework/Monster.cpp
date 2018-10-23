#include "Game.h"
#include <SDL_image.h>
#include <iostream>
#include "TextureManager.h"
#include "Enemy.h"
#include "GameObject.h"
#include "Monster.h"

using namespace std;

void Monster::update() {
	m_x += 1;
	SDL_Delay(1000);
	m_x -= 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}