#include "Player.h"
#include "InputHandler.h"
#include "Enemy.h"
#include "SDL.h"


Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}
void Player::draw()
{
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
}


void Player::update()
{
	//m_x -= 1;
	//m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	m_velocity.setX(0);
	m_velocity.setY(0);
	handleInput();

	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));

	//m_acceleration.setX(1);

	SDLGameObject::update();

}
void Player::clean()
{
}


void Enemy::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100;

}