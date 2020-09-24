#include "standardUse.h"
#include "WindowsWdw.h"

namespace VIIL
{
	std::unique_ptr<Window> createWindow(const Window::WindowData& winData)
	{
		return std::make_unique<WindowsWdw>(winData);
	}

	WindowsWdw::WindowsWdw(const WindowData& winData)
	{
		initializeWindow(winData);
	}

	/*
	* NOTE: Can only be called on the main thread
	*/
	void WindowsWdw::initializeWindow(const WindowData& winData)
	{
		VL_ENGINE_TRACE("Initializing new Windows window");
		wData.height = winData.height;
		wData.width = winData.width;
		wData.title = winData.title;
		wData.isFullScreen = winData.isFullScreen;

		
		//glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_FALSE);
		
		//glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
		//glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_NATIVE_CONTEXT_API);
		//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

		glfwDefaultWindowHints();

		windowHndl = glfwCreateWindow(wData.width, wData.height, wData.title.c_str(), NULL, NULL);

		if (!windowHndl)
		{
			//const char* message;
			//int errorCode = glfwGetError(&message);
			//VL_ENGINE_FATAL("GLFW Error: ", errorCode, " - ", message);
			throw std::exception::exception("Failed to create window");
		}

		//glfwSetWindowCloseCallback(windowHndl, glfw_window_close_callback);

		glfwMakeContextCurrent(windowHndl);
		glfwSetWindowUserPointer(windowHndl, &wData);
		glfwSwapInterval(1);
	}

	WindowsWdw::~WindowsWdw()
	{
		glfwDestroyWindow(windowHndl);
		VL_ENGINE_TRACE("Destroyed Windows window");
	}

	void WindowsWdw::update()
	{
		glfwPollEvents();
		glfwSwapBuffers(windowHndl);
	}

}
