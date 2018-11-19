#pragma once
#include "LoaderParams.h"
#include "SDL.h"
#include <iostream>


class GameObject
{
public:
	virtual void draw(SDL_Renderer* pRenderer) = 0;	//�ٸ� Ŭ�������� �������̵� �ϱ����� ���� �����Լ�
	virtual void draw() = 0;						//�ٸ� Ŭ�������� �������̵� �ϱ����� ���� �����Լ�
	virtual void update() = 0;						//�ٸ� Ŭ�������� �������̵� �ϱ����� ���� �����Լ�
	virtual void clean() = 0;						//�ٸ� Ŭ�������� �������̵� �ϱ����� ���� �����Լ�
	virtual void load(int x, int y, int width, int height,std::string textureID);

protected:

	GameObject(const LoaderParams* pParams) : m_pParams(pParams) {} //������
	virtual ~GameObject() {}										//�Ҹ���

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
