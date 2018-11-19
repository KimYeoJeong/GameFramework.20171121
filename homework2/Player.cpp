#include "Player.h"
#include "bullet.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Player::draw()
{
	for (int i = 0; i < m_bullets.size(); i++)
	{
		m_bullets[i]->draw();
	}
	SDLGameObject::draw(); // we now use SDLGameObject
}



void Player::handleInput()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_velocity.setX(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		m_velocity.setX(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		m_velocity.setY(-2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
	{
		m_velocity.setY(2);
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		m_bullets.push_back(new bullet(new LoaderParams(m_position.getX(), m_position.getY(), 100, 100, "animate1")));
	}
}


void Player::update()
{
	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	SDLGameObject::update();
	for (int i = 0; i < m_bullets.size(); i++)
	{
		m_bullets[i]->update();
	}
}
void Player::clean()
{
	for (int i = 0; i < m_bullets.size(); i++)
	{
		delete m_bullets[i];
	}
	m_bullets.clear();
}