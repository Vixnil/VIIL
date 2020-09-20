#pragma once

#include "core.h"
#include "Logger.h"
#include <string>

namespace VIIL
{
	class VIIL_API Application
	{
		//Class variable used to stop application running in the run method
		bool appIsRunning;

	public:
		LogConfig appLogConfig;
		VIIL::LEVEL engineLogLevel;

	public:
		Application();
		Application(VIIL::LEVEL engineLogLevel, std::string appName, std::string logPattern, VIIL::LEVEL logLevel);

		~Application();

		virtual void run();
	};

	VIIL::Application* createApplication();
}

