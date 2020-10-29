#pragma once

#include "core/standardUse.h"
#include "renderer/interface/Graphics.h"
#include "event/app.h"
#include "event/key.h"
#include "event/mouse.h"

namespace VIIL
{
	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		struct WindowData
		{
			std::string title;
			unsigned int width, height;
			bool isFullScreen;

			EventCallbackFn callBackFn;
		};

	protected:
		WindowData wData;
		std::unique_ptr<Graphics, GraphicsDeleter> appGraphics;
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

	std::shared_ptr<Window> createWindow(const Window::WindowData& winData);
}
