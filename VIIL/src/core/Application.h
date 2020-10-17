#pragma once

#include "standardUse.h"
#include "LayerStack.h"
#include "Window.h"
#include "Graphics.h"
#include "core/input/inputValues.h"

namespace VIIL
{
	class VIIL_API Application
	{
		//Class variable used to stop application running in the run method
		bool appIsRunning;
		std::unique_ptr<Graphics, GraphicsDeleter> appGraphics;
		std::unique_ptr<Window> appWindow;
		VIIL::Window::WindowData initialWindowDef;
		VIIL::LayerStack layerStack;

		static Application* applicationInstance;

		using layerPtnr = std::shared_ptr<VIIL::Layer>;

	public:
		LogConfig appLogConfig;
		VIIL::LEVEL engineLogLevel;

		Application(VIIL::LEVEL engineLogLevel, const LogConfig& appLogData, VIIL::Window::WindowData windDef);

		virtual ~Application();
		void run();
		void doStart();
		void OnEvent(Event& event);
		void pushLayer(layerPtnr layer);
		void pushOverlay(layerPtnr overlay);

		inline static Application& getApp() { return *applicationInstance; }
		inline Window& getWindow() { return *(appWindow.get()); }

		virtual void prepareDelete() {}

	private:
		bool windowCloseHandler(WindowClose& event);
	};

	struct ApplicationDeleter
	{
		void operator()(Application* app) const
		{
			app->prepareDelete();
			delete app;
		}
	};

	std::unique_ptr<VIIL::Application, VIIL::ApplicationDeleter> createApplication();
}

