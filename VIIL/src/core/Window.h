#pragma once

#include "standardUse.h"
#include "core/event/app.h"
#include "core/event/key.h"
#include "core/event/mouse.h"

namespace VIIL
{

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		struct WindowData
		{
			std::string title;
			int width, height;
			bool isFullScreen;

			EventCallbackFn callBackFn;
		};

	protected:
		WindowData wData;
		bool initialized;

	public:

		~Window()
		{
			VL_ENGINE_TRACE("Default window destructor called.");
		}

		virtual void update() = 0;
		virtual inline unsigned int getWidth() { return wData.width; }
		virtual inline unsigned int getHeight() { return wData.height; }

		virtual void setEventCallback(const EventCallbackFn& callback) = 0;

		bool isInitialized()
		{
			return initialized;
		}

	};

	std::unique_ptr<Window> createWindow(const Window::WindowData& winData);
}
