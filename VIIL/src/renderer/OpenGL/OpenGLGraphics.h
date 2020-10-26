#pragma once
#include "core/standardUse.h"
#include "platform/interface/Window.h"
#include "renderer/interface/Graphics.h"
#include "renderer/OpenGL/OpenGLInclude.h"

namespace VIIL
{

    /*
	* This needs to be on each thread GLFW will be on as GLFW will call the callback on the same thread only
	* NOTE: Error callback stays set after library has been terminated as well!?!?!??
	*/
	static void glfw_error_callback(int error, const char* description)
	{
		VL_ENGINE_ERROR(("GLFW: {0}: {1}", error, description));
	}

	class OpenGLGraphics : public Graphics
	{
		GLFWwindow* windowHandle = nullptr;
	public:

		virtual void createWindow(unsigned int& width, unsigned int& height, std::string titleString, void* userData) override;
		virtual void swapBuffers() override;
		virtual void isVsync(bool isVSyncOn) override;

		void tempTesting()
		{
		}

		void initialize();
		void destoryWindow();
		void prepareDelete();
	};

	std::unique_ptr<Graphics, GraphicsDeleter> initializeGraphics()
	{
		std::unique_ptr<OpenGLGraphics, GraphicsDeleter> gphs = std::unique_ptr<OpenGLGraphics, GraphicsDeleter>(new OpenGLGraphics());
		gphs->initialize();
		return gphs;
	}

}