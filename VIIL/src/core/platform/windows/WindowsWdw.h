#pragma once
#include "standardUse.h"
#include "core/Window.h"
#include <GLFW/glfw3.h>

namespace VIIL
{
	class WindowsWdw : public Window
	{
		GLFWwindow* windowHndl;
	public:
		WindowsWdw(const WindowData& winData);
		~WindowsWdw();

		void initializeWindow(const WindowData& winData);
		void WindowsWdw::update();
	};
}


