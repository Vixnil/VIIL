#include "core/standardUse.h"
#include "UserInterface/imguiLayer.h"
#include <imgui.h>

namespace VIIL
{
	void ImGuiLayer::onAttached()
	{
		VL_ENGINE_TRACE("ImGuiLayer attached");

		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();

		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		//set up backend flags
		//set up key code mapping
		//set up events?
	}

	void ImGuiLayer::onEvent(Event& event)
	{
	}

	void ImGuiLayer::onUpdate(float deltaTime)
	{

		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2((float)Application::getApp().getWindow().getWidth(), (float)Application::getApp().getWindow().getHeight());

		ImGui::NewFrame();

		bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
	}

}