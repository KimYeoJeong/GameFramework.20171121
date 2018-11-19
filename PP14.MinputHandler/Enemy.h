#pragma once
#include <map>
#include "GameObject.h"
#include "LoaderParams.h"
#include "SDLGameObject.h"


class Enemy : public SDLGameObject          
{
public:
	Enemy(const LoaderParams* pParams);	//Enemy 객체를 생성하는 함수 
	void draw();						//Enemy를 그려주는 함수
	void update();						//Enemy를 매 프레임 작동시켜 주는 함수
	void clean();						

	void handleInput();					//Enemy의 조작을 담당하는 함수
};