#include "standardUse.h"
#include "Application.h"
#include "platform/Platform.h"

namespace VIIL
{

#define bindEventHandler(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::applicationInstance = nullptr;

	Application::Application(VIIL::LEVEL engineLogLevel, const LogConfig& appLogData, VIIL::Window::WindowData windDef):
		appIsRunning(true), appLogConfig(appLogData.logName, appLogData.logPatrn, appLogData.logLevel), engineLogLevel(engineLogLevel)
	{
		VIIL::LogConfig engineConfig("VIIL", VIIL::Logger::defaultLogPattern, this->engineLogLevel);
		VIIL::Logger::init(engineConfig, this->appLogConfig);

		initialWindowDef = windDef;
		appWindow = createWindow(initialWindowDef);
		applicationInstance = this;

		VL_ENGINE_TRACE("Created application");
	}

	Application::~Application()
	{
		VL_ENGINE_TRACE("Destroyed application");
	}

	void Application::doStart()
	{
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
		float lastFrameTime = 0;
		VL_ENGINE_TRACE("Starting application");

		doStart();

		while (appIsRunning)
		{
			float currTime = Platform::get()->getClock()->getTimeInSeconds();
			float timeStep = currTime - lastFrameTime;
			lastFrameTime = currTime;

			for (layerPtnr layer : layerStack)
			{
				layer->onUpdate(timeStep);
			}

			MousePosition& pos = InputCache::get().getMousePosition();

			appWindow->update();
		}

		VL_ENGINE_TRACE("Application stopped, shutting down.");
	}

	void Application::OnEvent(Event& event)
	{
	//	VL_ENGINE_TRACE("Event occured: {0}", event.ToString());

		EventDispatcher dispatcher(event);
		dispatcher.dispatch<WindowClose>(bindEventHandler(windowCloseHandler));
		
		if (!event.isHandled())
		{
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
	}

	bool Application::windowCloseHandler(WindowClose& event)
	{
		appIsRunning = false;

		event.setHandled(true);

		return true;
	}

	void Application::pushLayer(layerPtnr layer)
	{
		layerStack.addLayer(layer);
		layer->onAttached();
	}

	void Application::pushOverlay(layerPtnr overlay)
	{
		layerStack.addOverlay(overlay);
		overlay->onAttached();
	}

}