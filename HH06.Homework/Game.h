#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>


class Game
{
public:
	Game() {}
	~Game() {}
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }


private:
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	int m_currentFrame;

	//GameObject m_go;
	//Player m_player;

	std::vector<GameObject*> m_gameObjects;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;
	GameObject* m_monster;

};


//프레임워크와 라이브러리 차이!!!!!!!