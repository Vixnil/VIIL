#pragma once
#include "core/standardUse.h"

namespace VIIL
{
	//Quick little definition to bind a given function as an event handler
	#define bindEventHandler(x) std::bind(&x, this, std::placeholders::_1)

	/*
	* List of event types
	*/
	enum class EventType : int
	{
		BadEvent = 0,
		WindowClosed,
		WindowResized,
		WindowFocused,
		WindowLostFocus,
		WindowMoved,
		KeyPressed,
		KeyReleased,
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};

	/*
	* List of event categories
	*/
	enum EventCategory : unsigned int
	{
		EVTCAT_BadCategory = 0,
		EVTCAT_Application = BIT(0),
		EVTCAT_Input       = BIT(1),
		EVTCAT_Key         = BIT(2),
		EVTCAT_Mouse       = BIT(3),
		EVTCAT_MouseButton = BIT(4)
	};

	#define EVENT_CLASS_TYPE(type) static EventType getStaticType() { return EventType::##type; }\
                               virtual EventType getType() const override { return getStaticType(); }\
                               virtual const char* getName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(cat) virtual int getCategoryFlags() const override { return cat; }

	/*
	* Base event class to be extended by and implemented in specific event types.
	*/
	class Event
	{
		friend class EventDispatcher;

	public:
		virtual VIIL::EventType getType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string ToString() const { return getName(); }
		virtual bool isHandled() { return handled; }
		virtual void setHandled(bool flag) { handled = flag; }

		inline bool isCategory(VIIL::EventCategory cat)
		{
			return getCategoryFlags() &cat;
		}

	protected:
		bool handled = false;
	};

	/*
	* Provides functionality to dispatch events to a provided event handler.
	* Only handles events of type T, other events will be ignored and the hanlder not called.
	*/
	class EventDispatcher
	{
	private:
		Event& event;

		template<typename T>
		using EventHandler = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& evnt):
			event(evnt)
		{}

		 template<typename T>
		 bool dispatch(EventHandler<T> handler)
		 {
			 if (event.getType() == T::getStaticType())
			 {
				 event.handled = handler((*(T*)&event));
				 return true;
			 }
			  
			 return false;
		 }

	};

	inline std::ostream& operator<<(std::ostream& strm, Event& event)
	{
		return strm << event.ToString();
	}

}