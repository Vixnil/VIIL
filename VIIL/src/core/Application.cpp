#include "standardUse.h"

namespace VIIL
{

	Application::Application(VIIL::LEVEL engineLogLevel, const LogConfig& appLogData, VIIL::Window::WindowData windDef):
		appIsRunning(true), appLogConfig(appLogData.logName, appLogData.logPatrn, appLogData.logLevel), engineLogLevel(engineLogLevel)
	{
		VIIL::LogConfig engineConfig("VIIL", VIIL::Logger::defaultLogPattern, this->engineLogLevel);
		VIIL::Logger::init(engineConfig, this->appLogConfig);

		initialWindowDef = windDef;
		appGraphics = VIIL_PLATFORM_GRAPHICS;

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
	}

	void Application::run()
	{
		VL_ENGINE_TRACE("Starting application");

		doStart();

		while (appIsRunning)
		{
			appWindow->update();
		}

		VL_ENGINE_TRACE("Application stopped, shutting down.");
	}

}