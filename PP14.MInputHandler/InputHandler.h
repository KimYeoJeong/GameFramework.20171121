#pragma once
#include "SDL.h"
#include "Vector2D.h"
#include <vector>

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

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

							
	std::vector<bool> m_mouseButtonStates;			
	Vector2D* m_mousePosition;

	void update();
	void clean();  // ����̽� ���� �ʱ�ȭ�� �κ��� clear 
	bool isKeyDown(SDL_Scancode key);

	void onKeyUp();
	void onKeyDown();
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	bool getMouseButtonState(int buttonNumber);
	Vector2D* getMousePosition();

private:
	InputHandler();
	~InputHandler() {}
	static InputHandler* s_pInstance;
};

typedef InputHandler TheInputHandler;