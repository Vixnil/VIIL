#pragma once
#include "core/standardUse.h"
#include "core/LayerStack.h"
#include "platform/interface/Window.h"
#include "input/inputValues.h"

namespace VIIL
{
	class Application
	{
		//Class variable used to stop application running in the run method
		bool appIsRunning;
		std::shared_ptr<Window> appWindow;
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

		unsigned int vertexArray, vertexBuffer, indexBuffer;
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

