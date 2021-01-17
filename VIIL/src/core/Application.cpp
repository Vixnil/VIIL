#include "core/standardUse.h"
#include "core/Application.h"
#include "platform/Platform.h"
#include "renderer/Renderer.h"

namespace VIIL
{
	Application* Application::applicationInstance = nullptr;

	Application::Application(VIIL::LEVEL engineLogLevel, const LogConfig& appLogData, VIIL::Window::WindowData windDef):
		appIsRunning(true), appIsMinimized(false), appLogConfig(appLogData.logName, appLogData.logPatrn, appLogData.logLevel), engineLogLevel(engineLogLevel)
	{
		VIIL::LogConfig engineConfig("VIIL", VIIL::Logger::defaultLogPattern, this->engineLogLevel);
		VIIL::Logger::init(engineConfig, this->appLogConfig);

		appWindow = createWindow(windDef);
		applicationInstance = this;

		Renderer::set(appWindow);

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
			appWindow->setEventCallback(bindEventHandler(Application::OnEvent));
		}
	}

	/*
	* Core application loop function.
	* Keeps track of frame delta time
	* Calls onUpdate for each layer already created and added to the layer stack
	* Stops when appIsRunning variable is false
	* Stops calling onUpdate for each layer when appIsMinimized is true
	*/
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

			if (!appIsMinimized)
			{
				for (layerPtnr layer : layerStack)
				{
					layer->onUpdate(timeStep);
				}
			}

			appWindow->update();
		}

		VL_ENGINE_TRACE("Application stopped, shutting down.");
	}

	void Application::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		//If the application wants to handle certain events, dispatch to an application event handler
		dispatcher.dispatch<WindowClose>(bindEventHandler(Application::windowCloseHandler));
		dispatcher.dispatch<WindowResize>(bindEventHandler(Application::windowResizeHandler));

		//Only continue if the application did not handle
		if (!event.isHandled())
		{
			/*
			* Let each layer handle the event in reverse order of layer update.
			* This is so the last layer rendered, usually overlays, have a chance to handle the event
			* before layers rendered sooner, like backgrounds.
			*/
			for (LayerVector::iterator layerItr = layerStack.end(); layerItr != layerStack.begin();)
			{
				--layerItr;
				layerItr->get()->onEvent(event);

				if (event.isHandled())
				{
					//A layer handled the event and wants to block the event propagating to lower layers.
					break;
				}
			}
		}
	}

	/*
	* Stop the application, the window is closed.
	*/
	bool Application::windowCloseHandler(WindowClose& event)
	{
		VL_ENGINE_TRACE("Window close handler triggered");
		appIsRunning = false;

		event.setHandled(true);

		return true;
	}

	/*
	* Check to see if the window was minimized. If minimized layers should stop
	* being rendered. 
	* 
	* If not minimized send the new window size to the renderer to update whatever needs
	* the new window size.
	*/
	bool Application::windowResizeHandler(WindowResize& event)
	{
		if (event.getWidth() == 0 || event.getHeight() == 0)
		{
			appIsMinimized = true;
		}
		else
		{
			appIsMinimized = false;
			Renderer::onWindowResize(event.getWidth(), event.getHeight());
		}

		return false;
	}

	/*
	* Add a layer to the layer stack
	*/
	void Application::pushLayer(layerPtnr layer)
	{
		layerStack.addLayer(layer);
		layer->onAttached();
	}

	/*
	* Add a layer to the end of the layer stack. Useful for overlays
	* since they will be rendered last.
	*/
	void Application::pushOverlay(layerPtnr overlay)
	{
		layerStack.addOverlay(overlay);
		overlay->onAttached();
	}

}