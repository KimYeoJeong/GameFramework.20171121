#pragma once
#include "GameObject.h"
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "SDL.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);		//Player ��ü�� �����ϴ� �Լ�
	void draw();								//Player�� �׷��ִ� �Լ�
	void update();								//Player�� �� ������ �۵����� �ִ� �Լ�
	void clean();								
private:
	void handleInput();//Player�� ������ ����ϴ� �Լ� 
};
