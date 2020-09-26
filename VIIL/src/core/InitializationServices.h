#include "standardUse.h"
#include "Graphics.h"

namespace VIIL
{
	void InitializeEngine(VIIL::RuntimeObjs* engineData, const VIIL::Application* app)
	{
		VIIL::LogConfig engineConfig("VIIL", VIIL::Logger::defaultLogPattern, app->engineLogLevel);
		VIIL::Logger::init(engineConfig, app->appLogConfig);
		engineData->g = VIIL_PLATFORM_GRAPHICS;

		if (!engineData->g->getIsInit())
		{
			throw std::exception("Failed to initialize graphics libraries.");
		}

		VL_ENGINE_TRACE("Finished initializing Engine");
	}

}