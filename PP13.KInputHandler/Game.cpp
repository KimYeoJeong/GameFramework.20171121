#include "Game.h"
#include <iostream>
#include <SDL_image.h>
#include "Enemy.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "InputHandler.h"
using namespace std;

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		if (m_pRenderer == 0)
		{
			return false;
		}

		m_bRunning = true;

		// load 부분 대치   
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}
		//m_go.load(100, 100, 128, 82, "animate");
		//m_player.load(300, 300, 128, 82, "animate");

		// init() 추가
		//m_go = new GameObject();
		//m_player = new Player();
		//m_enemy = new Enemy();

		//m_go->load(100, 100, 128, 82, "animate");
		//m_player->load(300, 300, 128, 82, "animate");
		//m_enemy->load(0, 0, 128, 82, "animate");
		m_gameObjects.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
		m_gameObjects.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));

		//m_gameObjects.push_back(m_go);
		//m_gameObjects.push_back(m_player);
		//m_gameObjects.push_back(m_enemy);

	}
	else {
		return false; // sdl could not initialize
	}
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear to the draw colour
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
	SDL_RenderPresent(m_pRenderer); // draw to the screen
}
void Game::update()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	TheInputHandler::Instance()->clean();
	SDL_Quit();
}

void Game::quit()
{

}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			clean();
			m_bRunning = false;
			break;
		default:
			break;
		}
	}

	TheInputHandler::Instance()->update();
}