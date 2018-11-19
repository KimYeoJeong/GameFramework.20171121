#include "bullet.h"
bullet::bullet(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void bullet::draw()
{
	if(!isCollide)
		SDLGameObject::draw(); // we now use SDLGameObject
}

void bullet::update()
{
	if (isCollide)
		return;

	Vector2D pos = m_position;
	if (boxPosX[0] < pos.getX() && boxPosX[1] > pos.getX() &&
		boxPosY[0] < pos.getY() && boxPosY[1] > pos.getY())
	{
		isCollide = true;
		
		//wall_break->wallbreak = false;
	}

	m_position.setX(m_position.getX() + 2);
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
}
void bullet::clean()
{
}