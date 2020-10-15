#include "standardUse.h"
#include "Application.h"

namespace VIIL
{

#define bindEventHandler(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application(VIIL::LEVEL engineLogLevel, const LogConfig& appLogData, VIIL::Window::WindowData windDef):
		appIsRunning(true), appLogConfig(appLogData.logName, appLogData.logPatrn, appLogData.logLevel), engineLogLevel(engineLogLevel)
	{
		VIIL::LogConfig engineConfig("VIIL", VIIL::Logger::defaultLogPattern, this->engineLogLevel);
		VIIL::Logger::init(engineConfig, this->appLogConfig);

		initialWindowDef = windDef;
		appGraphics = initializeGraphics();

		VL_ENGINE_TRACE("Created application");
	}

	Application::~Application()
	{
		VL_ENGINE_TRACE("Destroyed application");
	}

	void Application::doStart()
	{
		appWindow = createWindow(initialWindowDef);

		if (!appWindow->isInitialized())
		{
			appIsRunning = false;
		}
		else
		{
			appWindow->setEventCallback(bindEventHandler(OnEvent));
		}
	}

	void Application::run()
	{
		VL_ENGINE_TRACE("Starting application");

		doStart();

		while (appIsRunning)
		{

			for (layerPtnr layer : layerStack)
			{
				layer->onUpdate();
			}

			appWindow->update();
		}

		VL_ENGINE_TRACE("Application stopped, shutting down.");
	}

	void Application::OnEvent(Event& event)
	{
		VL_ENGINE_TRACE("Event occured: {0}", event.ToString());

		EventDispatcher dispatcher(event);
		dispatcher.dispatch<WindowClose>(bindEventHandler(windowCloseHandler));

		for (LayerVector::iterator layerItr = layerStack.end(); layerItr != layerStack.begin();)
		{
			--layerItr;
			layerItr->get()->onEvent(event);

			if (event.isHandled())
			{
				break;
			}
		}

	}

	bool Application::windowCloseHandler(WindowClose& event)
	{
		appIsRunning = false;

		return true;
	}

	void Application::pushLayer(layerPtnr layer)
	{
		layerStack.addLayer(layer);
	}

	void Application::pushOverlay(layerPtnr overlay)
	{
		layerStack.addOverlay(overlay);
	}

}