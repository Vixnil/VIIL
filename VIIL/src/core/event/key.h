#pragma once

#include "standardUse.h"

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


}