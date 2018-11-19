#pragma once
#include <map>
#include "GameObject.h"
#include "LoaderParams.h"
#include "SDLGameObject.h"


class Wall : public SDLGameObject
{
public:

	Wall(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	bool wallbreak  = false;

};