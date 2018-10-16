#include "Game.h"
#include <iostream>
#include <SDL_image.h>

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

		m_bRunning = true;

		// load 부분 대치   
		//if (!TheTextureManager::Instance()->load("assets/tree.gif", "animate", m_pRenderer))
		/*{
			return false;
		}*/
		TheTextureManager::Instance()->load("assets/tree.gif", "animate", m_pRenderer);
		TheTextureManager::Instance()->load("assets/dog.gif", "animate1", m_pRenderer);
		TheTextureManager::Instance()->load("assets/floor.gif", "animate2", m_pRenderer);
	}
	else {
		return false; // sdl could not initialize
	}
	return true;
}


void Game::render()
{

	SDL_RenderClear(m_pRenderer);
	SDL_RenderClear(m_pRenderer_1);
	TheTextureManager::Instance()->draw("animate1", 50, 0, 128, 82, m_pRenderer);
	TheTextureManager::Instance()->draw("animate", 100, 0, 128, 82, m_pRenderer);
	TheTextureManager::Instance()->draw("animate", 10, 0, 128, 82, m_pRenderer);
	//TheTextureManager::Instance()->draw("animate1", 30, 0, 128, 82, m_pRenderer);
	TheTextureManager::Instance()->draw("animate2", 0, 0, 128, 82, m_pRenderer);
	TheTextureManager::Instance()->draw("animate2", 100, 0, 128, 82, m_pRenderer);



	SDL_RenderPresent(m_pRenderer);
	SDL_RenderPresent(m_pRenderer_1);

}

void Game::update()
{
	//m_currentFrame = int(((SDL_GetTicks() / 100)));
	//m_currentFrame1 = int(((SDL_GetTicks() / 200) % 6));
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_DestroyRenderer(m_pRenderer_1);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}