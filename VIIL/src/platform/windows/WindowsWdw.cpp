#include "core/standardUse.h"
#include "platform/windows/WindowsWdw.h"

namespace VIIL
{

	WindowsWdw::WindowsWdw(const WindowData& winData)
	{
		appGraphics = initializeGraphics();
		initializeWindow(winData);
	}

	/*
	* NOTE: Can only be called on the main thread due to OpenGL restrictions
	*/
	void WindowsWdw::initializeWindow(const WindowData& winData)
	{
		VL_ENGINE_TRACE("Initializing new Windows window");
		wData.height = winData.height;
		wData.width = winData.width;
		wData.title = winData.title;
		wData.isFullScreen = winData.isFullScreen;

		appGraphics->createWindow(wData.width, wData.height, wData.title, &wData);
		appGraphics->isVsync(true);

		initialized = true;
	}

	WindowsWdw::~WindowsWdw()
	{
		//TODO: Not yet being called, need to fix.
		VL_ENGINE_TRACE("Destroyed Windows window");
	}

	void WindowsWdw::update()
	{
		appGraphics->swapBuffers();
	}

}