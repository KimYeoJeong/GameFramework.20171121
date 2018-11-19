#include <iostream>
#include "GameObject.h"
#include "TextureManager.h"
#include "stdio.h"
#include "Vector2D.h"
#include "SDLGameObject.h"
#include "InputHandler.h"

void GameObject::load(int x, int y, int width, int height,
	std::string textureID)//다른 함수에서 받아온 값으로 초기화 시키기위해 만듦
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureID = textureID;
	m_currentRow = 1;
	m_currentFrame = 1;
}

