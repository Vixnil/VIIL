#pragma once

#include "core/standardUse.h"
#include "event/event.h"

namespace VIIL
{
	/*
	* Object to be stored in a stack to represent an object to handle things
	* such as rendering and events.
	*/
	class Layer
	{
	protected:
		std::string name;

	public:
		Layer(const std::string& name = "Default") : 
			name(name)
		{ VL_ENGINE_TRACE("Default layer constructor"); }

		virtual ~Layer() { VL_ENGINE_TRACE("Default layer destructor"); }
		virtual void onAttached() {}
		virtual void onDetached() {}
		virtual void onUpdate(float deltaTime) {}
		virtual void onEvent(Event& event) {}

		inline const std::string& getName() const { return name; }
	};
}