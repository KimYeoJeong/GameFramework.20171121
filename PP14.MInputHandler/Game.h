#pragma once
#include "SDL.h"
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>


class Game
{
private:

	Game() {};
	static Game* s_pInstance;

	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	int m_currentFrame;

	std::vector<GameObject*> m_gameObjects;

	GameObject* m_go;
	GameObject* m_player;
	GameObject* m_enemy;

public:
	bool init(const char* title, int xpos, int ypos,
		int width, int height, bool fullscreen);
	void render();		//m_gameobject의 저장되어있는 데이터들을 그려주는함수
	void update();		//매 프레임마다 동작하는 함수
	void handleEvents();	//조작을 담당하는 함수
	void clean();
	void quit();			//꺼주는 함수
	bool running() { return m_bRunning; }

	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	static Game* Instance()					//객체를 하나만 생성하기위해 싱글톤 패턴을 사용
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}

};

#pragma once

typedef Game TheGame;