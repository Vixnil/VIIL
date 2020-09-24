#pragma once

#include "standardUse.h"

namespace VIIL
{

	class VIIL_API Window
	{
	public:
		struct WindowData
		{
			std::string title;
			int width, height;
			bool isFullScreen;

		};

	protected:
		WindowData wData;

	public:

		virtual ~Window() {}
		virtual void update() = 0;
		virtual inline unsigned int getWdith() { return wData.width; }
		virtual inline unsigned int getHeight() { return wData.height; }

	};

	std::unique_ptr<Window> createWindow(const Window::WindowData& winData);
}
