#pragma once
#include "standardUse.h"
#include "Window.h"

namespace VIIL
{
	class VIIL_API Application
	{
		//Class variable used to stop application running in the run method
		bool appIsRunning;
		std::unique_ptr<Window> appWindow;
		VIIL::Window::WindowData initialWindowDef;

	public:
		LogConfig appLogConfig;
		VIIL::LEVEL engineLogLevel;

	public:
		Application(VIIL::LEVEL engineLogLevel, const LogConfig& appLogData, VIIL::Window::WindowData windDef);
		~Application();

		virtual void run();
		virtual void doStart();
	};

	std::unique_ptr<VIIL::Application> createApplication();
}

