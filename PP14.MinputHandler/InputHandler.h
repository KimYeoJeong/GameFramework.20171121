#pragma once
#include "SDL.h"
#include "Vector2D.h"
#include "InputHandler.h"
#include <iostream>
#include "stdio.h"
#include <vector>

using namespace std;


//std::vector<bool> m_mouseButtonStates;
enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};



//std::vector<bool> m_mouseButtonStates;
class InputHandler
{
	const Uint8* m_keystates;

public:
	static InputHandler* Instance()
	{
		if (s_pInstance == 0) {
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	// handle keyboard events
	void onKeyDown();
	void onKeyUp();
	// handle mouse events
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);


	std::vector<bool> m_mouseButtonStates;
	Vector2D* m_mousePosition;



	Vector2D* getMousePosition();

	void update();
	void clean();  // 디바이스 관련 초기화된 부분을 clear 
	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);
private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
};

typedef InputHandler TheInputHandler;