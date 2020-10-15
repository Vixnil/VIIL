#pragma once

#include "standardUse.h"
#include "core/Window.h"
#include "core/platform/windows/WindowsGraphics.h"

namespace VIIL
{
	class WindowsWdw : public Window
	{
		GLFWwindow* windowHndl;
	public:
		WindowsWdw(const WindowData& winData);
		virtual ~WindowsWdw();

		void initializeWindow(const WindowData& winData);
		void WindowsWdw::update();

		inline void setEventCallback(const EventCallbackFn& callback) override { wData.callBackFn = callback; }

	};
}


