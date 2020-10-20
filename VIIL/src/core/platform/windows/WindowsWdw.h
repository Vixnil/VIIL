#pragma once

#include "standardUse.h"
#include "core/Window.h"

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

	std::unique_ptr<Window> createWindow(const Window::WindowData& winData)
	{
		return std::make_unique<WindowsWdw>(winData);
	}
}


