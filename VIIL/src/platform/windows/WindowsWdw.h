#pragma once
#include "core/standardUse.h"
#include "platform/interface/Window.h"

namespace VIIL
{
	class WindowsWdw : public Window
	{
	public:
		WindowsWdw(const WindowData& winData);
		virtual ~WindowsWdw();

		void initializeWindow(const WindowData& winData);
		void WindowsWdw::update();

		inline void setEventCallback(const EventCallbackFn& callback) override { wData.callBackFn = callback; }
	};

	std::shared_ptr<Window> createWindow(const Window::WindowData& winData)
	{
		return std::make_shared<WindowsWdw>(winData);
	}
}


