#pragma once
#include "core/standardUse.h"
#include "input/inputValues.h"
#include "event/event.h"

namespace VIIL
{
	
	/*
	* Super class for mouse button events
	*/
	class MouseButtonEvent : public Event
	{
	protected:
		VIIL_MouseCode code;

		MouseButtonEvent(VIIL_MouseCode btnCode):
			code(btnCode)
		{}

		EVENT_CLASS_CATEGORY(EVTCAT_Mouse | EVTCAT_MouseButton | EVTCAT_Input)
	};
		
	/*
	* Event for mouse button pressed events
	*/
	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(VIIL_MouseCode btnCode):
			MouseButtonEvent(btnCode)
		{
			InputCache::get().setMouseButtonPressed(btnCode, true);
		}

		std::string ToString() const override
		{
			std::stringstream strm;
			strm << getName() << ": " << "button pressed: " << code;
			return strm.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	/*
	* Event for mouse button released events
	*/
	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(VIIL_MouseCode btnCode) :
			MouseButtonEvent(btnCode)
		{
			InputCache::get().setMouseButtonPressed(btnCode, false);
		}

		std::string ToString() const override
		{
			std::stringstream strm;
			strm << getName() << ": " << "button released: " << code;
			return strm.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

	/*
	* Event for handling when the mouse scroll wheel is moved.
	*/
	class MouseScrolledEvent : public Event
	{
		float xDiff, yDiff;

	public:
		MouseScrolledEvent(float xOffset, float yOffset):
			xDiff(xOffset), yDiff(yOffset)
		{}

		inline float getXOffset() const { return xDiff; }
		inline float getYOffset() const { return yDiff; }

		std::string ToString() const override
		{
			std::stringstream strm;
			strm << getName() << ": " << "xDiff: " << xDiff << " yDiff: " << yDiff;
			return strm.str();
		}

		EVENT_CLASS_CATEGORY(EVTCAT_Mouse | EVTCAT_Input)
		EVENT_CLASS_TYPE(MouseScrolled)
	};

	/*
	* Event for handling when the cursor on a window is moved
	*/
	class MouseMovedEvent : public Event
	{
		float x, y;

	public:
		MouseMovedEvent(float x, float y):
			x(x), y(y)
		{
			InputCache::get().setMousePosition(x, y);
		}

		inline float getX() const { return x; }
		inline float getY() const { return y; }

		std::string ToString() const override
		{
			std::stringstream strm;
			strm << getName() << ": " << "x: " << x << " y: " << y;
			return strm.str();
		}

		EVENT_CLASS_CATEGORY(EVTCAT_Mouse | EVTCAT_Input)
		EVENT_CLASS_TYPE(MouseMoved)
	};

}