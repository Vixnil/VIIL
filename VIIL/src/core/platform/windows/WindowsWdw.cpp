#include "standardUse.h"
#include "WindowsWdw.h"

namespace VIIL
{

	WindowsWdw::WindowsWdw(const WindowData& winData)
	{
		appGraphics = initializeGraphics();
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

		appGraphics.get()->createWindow(wData.width, wData.height, wData.title, &wData);

		initialized = true;
	}

	WindowsWdw::~WindowsWdw()
	{
		VL_ENGINE_TRACE("Destroyed Windows window");
	}

	void WindowsWdw::update()
	{
		appGraphics.get()->swapBuffers();
	}

}
