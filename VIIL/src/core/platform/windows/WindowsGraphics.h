#pragma once

#include "core/Logger.h"
#include "core/Graphics.h"

namespace VIIL
{
    /*
	* This needs to be on each thread GLFW will be on as GLFW will call the callback on the same thread only
	* NOTE: Error callback stays set after library has been terminated as well!?!?!??
	*/
	static void glfw_error_callback(int error, const char* description)
	{
		VL_ENGINE_ERROR(("GLFW: ", error, " - ", description));
	}
	
	/*
	void glfw_window_close_callback(GLFWwindow* window)
	{
		VL_ENGINE_TRACE("User pressed the close button.");
	}
	*/

	class WindowsGraphics : public Graphics
	{
		
	public:
		WindowsGraphics()
		{
		}

		void initialize()
		{
			glfwSetErrorCallback(glfw_error_callback);
			isInit = glfwInit();

			VL_ENGINE_TRACE("Initialized windows graphics");
		}

		static std::unique_ptr<Graphics, GraphicsDeleter> initializeGraphics()
		{
			std::unique_ptr<WindowsGraphics, GraphicsDeleter> gphs = std::unique_ptr<WindowsGraphics, GraphicsDeleter>(new WindowsGraphics());

			gphs->initialize();
			return gphs;
		}

		void prepareDelete()
		{
			glfwTerminate();
			VL_ENGINE_TRACE("Destroyed windows graphics");
		}
	};
}