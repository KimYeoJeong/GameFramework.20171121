#pragma once

#include "SDL.h"
#include <map>

class TextureManager {
private:
	static TextureManager* s_pInstance;

	TextureManager() {} //생성자
	std::map<std::string, SDL_Texture*> m_textureMap;

public:
	~TextureManager() {}	//소멸자

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	void draw(std::string id, int x, int y, int width, int height,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void drawFrame(std::string id, int x, int y, int width, int height,
		int currentRow, int currentFrame,
		SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	static TextureManager* Instance()		//객체를 하나만 생성하기위해 싱글톤 패턴을 사용
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

};

typedef TextureManager TheTextureManager;
