#pragma once
#include "core/standardUse.h"
#include "core/Application.h"

namespace VIIL
{

	class ImGuiLayer : public VIIL::Layer
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
		void onUpdate(float deltaTime) override;

	};

}
