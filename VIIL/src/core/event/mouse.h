#pragma once

#include "core/event/event.h"

namespace VIIL
{
	enum MouseBtnCode : int
	{
		BTN_1 = 0
		, BTN_2
		, BTN_3
		, BTN_4
		, BTN_5
		, BTN_6
		, BTN_7
		, BTN_8
		, BTN_UNSUPPORTED
		, BTN_LEFT = BTN_1
		, BTN_RIGHT = BTN_2
		, BTN_MIDDLE = BTN_3
	};

		class VIIL_API MouseButtonEvent : public Event
		{
		protected:
			int code;

			MouseButtonEvent(int btnCode):
				code(btnCode)
			{}

			EVENT_CLASS_CATEGORY(EVTCAT_Mouse | EVTCAT_MouseButton | EVTCAT_Input)
		};
		
		class VIIL_API MouseButtonPressedEvent : public MouseButtonEvent
		{
		public:
			MouseButtonPressedEvent(int btnCode):
				MouseButtonEvent(btnCode)
			{}

			std::string ToString() const override
			{
				std::stringstream strm;
				strm << getName() << ": " << "button pressed: " << code;
				return strm.str();
			}

			EVENT_CLASS_TYPE(MouseButtonPressed)
		};

		class VIIL_API MouseButtonReleasedEvent : public MouseButtonEvent
		{
		public:
			MouseButtonReleasedEvent(int btnCode) :
				MouseButtonEvent(btnCode)
			{}

			std::string ToString() const override
			{
				std::stringstream strm;
				strm << getName() << ": " << "button released: " << code;
				return strm.str();
			}

			EVENT_CLASS_TYPE(MouseButtonReleased)
		};

		class VIIL_API MouseScrolledEvent : public Event
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

		class VIIL_API MouseMovedEvent : public Event
		{
			float x, y;

		public:
			MouseMovedEvent(float x, float y):
				x(x), y(y)
			{}

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