#include "Application.h"

namespace VIIL
{
	Application::Application() :
		appIsRunning(false), appLogConfig("", "", VIIL::LEVEL::LV_UNKNOWN), engineLogLevel(VIIL::LEVEL::LV_UNKNOWN)
	{

	}

	Application::Application(VIIL::LEVEL engineLogLevel, std::string appName, std::string logPattern, VIIL::LEVEL logLevel):
		appIsRunning(true), appLogConfig(appName, logPattern, logLevel), engineLogLevel(engineLogLevel)
	{

	}

	Application::~Application()
	{

	}

	void Application::run()
	{
		while (this->appIsRunning)
		{

		}
	}

}