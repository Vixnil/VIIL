#include "Application.h"

namespace VIIL
{

	void InitializeEngine(const VIIL::Application* app)
	{
		VIIL::LogConfig engineLogConfig("VIIL", Logger::defaultLogPattern, app->engineLogLevel);

		VIIL::Logger::init(engineLogConfig, app->appLogConfig);
	}

}