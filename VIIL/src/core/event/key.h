#pragma once

#include "core/event/event.h"

namespace VIIL
{
	class VIIL_API KeyEvent : public Event
	{
	protected:
		int keyCode;

		KeyEvent(int code) :
			keyCode(code)
		{}

	public:
		inline int getKeyCode() const { return keyCode; }

		EVENT_CLASS_CATEGORY(EVTCAT_Key | EVTCAT_Input)
	};

	class VIIL_API KeyPressedEvent : public KeyEvent
	{
	protected:
		int numRepeated;

	public:
		KeyPressedEvent(int code, int numRepeat):
			KeyEvent(code), numRepeated(numRepeat)
		{}

		std::string ToString() const override
		{
			std::stringstream strm;
			strm << getName() << ": " << "key pressed: " << keyCode << " repeated: " << numRepeated;
			return strm.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class VIIL_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int code):
			KeyEvent(code)
		{}

		std::string ToString() const override
		{
			std::stringstream strm;
			strm << getName() << ": " << "key released: " << keyCode;
			return strm.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};


	enum VIIL_API KeyCode : int
	{
		UNKNOWN = -1
		,SPACE ,APOSTROPHE ,COMMA ,MINUS ,PERIOD ,SLASH ,BACK_SLASH ,SEMICOLON ,EQUAL ,LEFT_BRACKET ,RIGHT_BRACKET ,GRAVE_ACCENT ,ESCAPE ,ENTER ,TAB ,BACKSPACE ,INSERT
		,DELETE_KEY ,RIGHT_ARROW ,LEFT_ARROW ,UP_ARROW ,DOWN_ARROW ,PAGE_UP ,PAGE_DOWN ,HOME ,END ,CAPS_LOCK ,SCROLL_LOCK ,NUM_LOCK ,PRINT_SCREEN ,PAUSE_BREAK
		,LEFT_SHIFT ,RIGHT_SHIFT ,LEFT_CONTROL ,RIGHT_CONTROL ,LEFT_ALT ,RIGHT_ALT ,LEFT_SUPER ,RIGHT_SUPER ,MENU
		,ZERO ,ONE ,TWO ,THREE ,FOUR ,FIVE ,SIX ,SEVEN ,EIGHT ,NINE
		,A ,B ,C ,D ,E ,F ,G ,H ,I ,J ,K ,L ,M ,N ,O ,P ,Q ,R ,S ,T ,U ,V ,W ,X ,Y ,Z
		,F1 ,F2 ,F3 ,F4 ,F5 ,F6 ,F7 ,F8 ,F9 ,F10 ,F11 ,F12 ,F13 ,F14 ,F15 ,F16 ,F17 ,F18 ,F19 ,F20 ,F21 ,F22 ,F23 ,F24 ,F25
		,KP_ZERO ,KP_ONE ,KP_TWO ,KP_THREE ,KP_FOUR ,KP_FIVE ,KP_SIX ,KP_SEVEN ,KP_EIGHT ,KP_NINE
		,KP_DECIMAL ,KP_DIVIDE ,KP_MULTIPLY ,KP_SUBTRACT ,KP_ADD ,KP_ENTER ,KP_EQUAL
		,LAST_KEY_CODE_IN_USE
	};


}