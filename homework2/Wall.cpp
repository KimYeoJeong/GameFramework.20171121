#include "Wall.h"

Wall::Wall(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	
}

void Wall::draw()
{
	if (!wallbreak)
		SDLGameObject::draw(); // we now use SDLGameObject

}

void Wall::update()
{

	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));

}

void Wall::clean()
{
}