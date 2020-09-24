#pragma once

#include "core/Logger.h"
#include "core/Graphics.h"

namespace VIIL
{
    /*
	* This needs to be on each thread GLFW will be on as GLFW will call the callback on the same thread only
	* NOTE: Error callback stays set after library has been terminated as well!?!?!??
	*/
	void glfw_error_callback(int error, const char* description)
	{
		VL_ENGINE_ERROR("GLFW: ", error, " - ", description);
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
		WindowsGraphics() :
			Graphics(initialize())
		{
			VL_ENGINE_TRACE("Initialized windows graphics");
		}

		bool initialize()
		{
			glfwSetErrorCallback(glfw_error_callback);
			int value = glfwInit();
			return value;
		}

		~WindowsGraphics()
		{
			glfwTerminate();
			VL_ENGINE_TRACE("Destroyed windows graphics");
		}
		
	};
}