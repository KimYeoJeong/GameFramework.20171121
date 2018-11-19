#pragma once
#include "LoaderParams.h"
#include "SDL.h"
#include <iostream>


class GameObject
{
public:
	virtual void draw(SDL_Renderer* pRenderer) = 0;	//다른 클래스에서 오버라이드 하기위해 만든 가상함수
	virtual void draw() = 0;						//다른 클래스에서 오버라이드 하기위해 만든 가상함수
	virtual void update() = 0;						//다른 클래스에서 오버라이드 하기위해 만든 가상함수
	virtual void clean() = 0;						//다른 클래스에서 오버라이드 하기위해 만든 가상함수
	virtual void load(int x, int y, int width, int height,std::string textureID);

protected:

	GameObject(const LoaderParams* pParams) : m_pParams(pParams) {} //생성자
	virtual ~GameObject() {}										//소멸자

	std::string m_textureID;
	int m_currentFrame;		
	int m_currentRow;		
	int m_x;
	int m_y;
	int m_width;
	int m_height;

	const LoaderParams* m_pParams;
};
#pragma once
