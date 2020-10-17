#pragma once

#include "standardUse.h"
#include "core/Application.h"

namespace VIIL
{

	class VIIL_API ImGuiLayer : public VIIL::Layer
	{

	public:
		ImGuiLayer():
			Layer("ImGuiLayer")
		{
			VL_ENGINE_TRACE("ImGuiLayer constructor");
		}

		~ImGuiLayer()
		{
			VL_ENGINE_TRACE("ImGuiLayer destroyed");
		}

		void onAttached() override;
		void onEvent(Event& event) override;
		void onUpdate() override;

	};

}
