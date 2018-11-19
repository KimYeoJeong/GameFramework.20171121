#pragma once
#include <map>
#include "GameObject.h"
#include "LoaderParams.h"
#include "SDLGameObject.h"


class Enemy : public SDLGameObject          
{
public:
	Enemy(const LoaderParams* pParams);	//Enemy ��ü�� �����ϴ� �Լ� 
	void draw();						//Enemy�� �׷��ִ� �Լ�
	void update();						//Enemy�� �� ������ �۵����� �ִ� �Լ�
	void clean();						

	void handleInput();					//Enemy�� ������ ����ϴ� �Լ�
};