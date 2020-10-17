#pragma once

#include "standardUse.h"

namespace VIIL
{
	enum VIIL_API VIIL_KeyCode : int
	{
		UNKNOWN = -1
		, SPACE, APOSTROPHE, COMMA, MINUS, PERIOD, SLASH, BACK_SLASH, SEMICOLON, EQUAL, LEFT_BRACKET, RIGHT_BRACKET, GRAVE_ACCENT, ESCAPE, ENTER, TAB, BACKSPACE, INSERT
		, DELETE_KEY, RIGHT_ARROW, LEFT_ARROW, UP_ARROW, DOWN_ARROW, PAGE_UP, PAGE_DOWN, HOME, END, CAPS_LOCK, SCROLL_LOCK, NUM_LOCK, PRINT_SCREEN, PAUSE_BREAK
		, LEFT_SHIFT, RIGHT_SHIFT, LEFT_CONTROL, RIGHT_CONTROL, LEFT_ALT, RIGHT_ALT, LEFT_SUPER, RIGHT_SUPER, MENU
		, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE
		, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
		, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15, F16, F17, F18, F19, F20, F21, F22, F23, F24, F25
		, KP_ZERO, KP_ONE, KP_TWO, KP_THREE, KP_FOUR, KP_FIVE, KP_SIX, KP_SEVEN, KP_EIGHT, KP_NINE
		, KP_DECIMAL, KP_DIVIDE, KP_MULTIPLY, KP_SUBTRACT, KP_ADD, KP_ENTER, KP_EQUAL
		, LAST_KEY_CODE_IN_USE
	};

	enum VIIL_API VIIL_MouseCode : int
	{
		BTN_UNKNOWN = -1
		, BTN_1
		, BTN_2
		, BTN_3
		, BTN_4
		, BTN_5
		, BTN_6
		, BTN_7
		, BTN_8
		, BTN_LAST_CODE_IN_USE
		, BTN_LEFT = BTN_1
		, BTN_RIGHT = BTN_2
		, BTN_MIDDLE = BTN_3
	};

	struct MousePosition
	{
		float posX, posY;
	};

	class VIIL_API InputCache
	{
		bool keyCache[VIIL_KeyCode::LAST_KEY_CODE_IN_USE];
		bool mouseButtonCache[VIIL_MouseCode::BTN_LAST_CODE_IN_USE];
		MousePosition mousePosCache;

		InputCache()
		{
			clearCache();
			VL_ENGINE_TRACE("InputCache constructor.");
		}

		~InputCache()
		{
			VL_ENGINE_TRACE("InputCache destructor.");
		}

		InputCache(InputCache const&) = delete;
		void operator=(InputCache const&) = delete;

	public:
		static InputCache& get()
		{
			static InputCache cache;

			return cache;
		}

		void clearCache()
		{
			mousePosCache.posX = 0.0;
			mousePosCache.posY = 0.0;

			for (int index = 0; index != VIIL_KeyCode::LAST_KEY_CODE_IN_USE; index++)
			{
				keyCache[index] = false;
			}

			for (int index = 0; index != VIIL_MouseCode::BTN_LAST_CODE_IN_USE; index++)
			{
				mouseButtonCache[index] = false;
			}
		}

		void setMousePosition(float x, float y)
		{
			mousePosCache.posX = x;
			mousePosCache.posY = y;
		}

		void setMousePosition(MousePosition position)
		{
			mousePosCache.posX = position.posX;
			mousePosCache.posY = position.posY;
		}

		MousePosition& getMousePosition()
		{
			return mousePosCache;
		}

		void setMouseButtonPressed(const VIIL_MouseCode& code, bool isPressed)
		{
			if (VIIL_MouseCode::BTN_UNKNOWN < code && code < VIIL_MouseCode::BTN_LAST_CODE_IN_USE)
			{
				mouseButtonCache[code] = isPressed;
			}
			else
			{
				VL_ENGINE_ERROR("Mouse Button {0} not supported", code);
			}
		}

		void setKeyPressed(const VIIL_KeyCode& code, bool isPressed)
		{
			if(VIIL_KeyCode::UNKNOWN < code && code < VIIL_KeyCode::LAST_KEY_CODE_IN_USE)
			{
				keyCache[code] = isPressed;
			}
			else
			{
				VL_ENGINE_ERROR("Button {0} not supported", code);
			}
		}

		bool& isMouseButtonPressed(const VIIL_MouseCode& code)
		{
			static bool returnable = false;

			if (VIIL_MouseCode::BTN_UNKNOWN < code && code < VIIL_MouseCode::BTN_LAST_CODE_IN_USE)
			{
				return mouseButtonCache[code];
			}
			else
			{
				VL_ENGINE_ERROR("Mouse Button {0} not supported", code);
				return returnable;
			}
		}

		bool& isKeyPressed(const VIIL_KeyCode& code)
		{
			static bool returnable = false;

			if (VIIL_KeyCode::UNKNOWN < code && code < VIIL_KeyCode::LAST_KEY_CODE_IN_USE)
			{
				return keyCache[code];
			}
			else
			{
				VL_ENGINE_ERROR("Button {0} not supported", code);
				return returnable;
			}
		}

	};

}

