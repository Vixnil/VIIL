#pragma once
#include "core/standardUse.h"
#include "event/event.h"

namespace VIIL
{

	/*
	* Event to be triggered when a window is closed
	*/
	class WindowClose : public Event
	{

	public:

		WindowClose()
		{}

		EVENT_CLASS_TYPE(WindowClosed)
		EVENT_CLASS_CATEGORY(EVTCAT_Application)
	};

	/*
	* Event to be used when a window is resized, includes minimized
	*/
	class WindowResize : public Event
	{
		unsigned int width, height;
	public:
		WindowResize(unsigned int w, unsigned int h):
			width(w), height(h)
		{}

		inline unsigned int getWidth() { return width; }
		inline unsigned int getHeight() { return height; }

		std::string ToString() const override
		{ 
			std::stringstream strm;
			strm << getName() << ": " << "width: " << width << " hight: " << height;
			return strm.str(); 
		}

		EVENT_CLASS_TYPE(WindowResized)
		EVENT_CLASS_CATEGORY(EVTCAT_Application)
	};

	/*
	* Event to be used when a window gains focus
	*/
	class WindowFocus : public Event
	{

	public:
		WindowFocus()
		{}

		EVENT_CLASS_TYPE(WindowFocused)
		EVENT_CLASS_CATEGORY(EVTCAT_Application)
	};

	/*
	* Event to be used when a window loses focus
	*/
	class WindowLoseFocus : public Event
	{

	public:
		WindowLoseFocus()
		{}

		EVENT_CLASS_TYPE(WindowLostFocus)
		EVENT_CLASS_CATEGORY(EVTCAT_Application)
	};

	/*
	* Event to be used when a window is moved on the screen.
	*/
	class WindowMove : public Event
	{

	public:
		WindowMove()
		{}

		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EVTCAT_Application)
	};

}