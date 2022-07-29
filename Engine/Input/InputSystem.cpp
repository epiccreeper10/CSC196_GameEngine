#include "InputSystem.h"
#include <SDL.h>
#include <iostream>
namespace neu {
	const uint32_t key_space = SDL_SCANCODE_SPACE;
	const uint32_t key_up = SDL_SCANCODE_UP;
	const uint32_t key_down = SDL_SCANCODE_DOWN;
	const uint32_t key_left = SDL_SCANCODE_LEFT;
	const uint32_t key_right = SDL_SCANCODE_RIGHT;
	const uint32_t key_escape = SDL_SCANCODE_ESCAPE;
	const uint32_t key_j = SDL_SCANCODE_J;
	const uint32_t key_tab = SDL_SCANCODE_TAB;

	void neu::InputSystem::Initialize()
	{
		const uint8_t* keyboardState = SDL_GetKeyboardState(&m_numKeys);
		m_keyboardState.resize(m_numKeys);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());

		m_prevKeyboardState = m_keyboardState;
	}

	void neu::InputSystem::Shutdown()
	{
		//
	}

	void neu::InputSystem::Update()
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		// Save previous keyboard state
		m_prevKeyboardState = m_keyboardState;

		// Get current keyboard state
		const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keyboardState.begin());


		//for (auto state : m_keyboardState)
		//{
		//	std::cout << state;
		//}
	}
	InputSystem::KeyState InputSystem::GetKeyState(uint32_t key)
	{
	
		KeyState keyState = KeyState::Idle;

		bool keyDown = GetKeyDown(key);
		bool prevKeyDown = GetPreviousKeyDown(key);

		if (keyDown && prevKeyDown)
		{
			keyState = KeyState::Held;
		}
		else if (keyDown && !prevKeyDown) {
			keyState = KeyState::Pressed;
		}
		else if (!keyDown && prevKeyDown) {
			keyState = KeyState::Released;
		}
		else if (!keyDown && !prevKeyDown) {
			keyState = KeyState::Idle;
		}

		return keyState;
	}
}

