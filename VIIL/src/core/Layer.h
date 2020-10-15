#pragma once

#include "standardUse.h"
#include "event/event.h"

namespace VIIL
{

	class VIIL_API Layer
	{
	protected:
		std::string name;

	public:
		Layer(const std::string& name = "Default") : name(name) { VL_ENGINE_TRACE("Default layer constructor"); }

		virtual ~Layer() { VL_ENGINE_TRACE("Default layer destructor"); }
		virtual void onAttached() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onEvent(Event& event) {}

		inline const std::string& getName() const { return name; }
	};

}