#pragma once

#include "core/input/inputValues.h"
#include "core/event/event.h"

namespace VIIL
{
	class KeyEvent : public Event
	{
	protected:
		VIIL_KeyCode keyCode;

		KeyEvent(VIIL_KeyCode code) :
			keyCode(code)
		{}

	public:
		inline VIIL_KeyCode getKeyCode() const { return keyCode; }

		EVENT_CLASS_CATEGORY(EVTCAT_Key | EVTCAT_Input)
	};

	class KeyPressedEvent : public KeyEvent
	{
	protected:
		int numRepeated;

	public:
		KeyPressedEvent(VIIL_KeyCode code, int numRepeat):
			KeyEvent(code), numRepeated(numRepeat)
		{
			InputCache::get().setKeyPressed(code, true);
		}

		std::string ToString() const override
		{
			std::stringstream strm;
			strm << getName() << ": " << "key pressed: " << keyCode << " repeated: " << numRepeated;
			return strm.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(VIIL_KeyCode code):
			KeyEvent(code)
		{
			InputCache::get().setKeyPressed(code, false);
		}

		std::string ToString() const override
		{
			std::stringstream strm;
			strm << getName() << ": " << "key released: " << keyCode;
			return strm.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

}