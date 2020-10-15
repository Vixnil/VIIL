#pragma once

#include "standardUse.h"
#include "Application.h"

#ifdef VIIL_PLATFORM_WINDOWS
extern std::unique_ptr<VIIL::Application, VIIL::ApplicationDeleter> VIIL::createApplication();

int main(int argc, char** argv)
{
	int returnCode = 0;
	{
		VIIL::Logger::initEngineLogger(VIIL::LogConfig("VIIL", VIIL::Logger::defaultLogPattern, VIIL::LEVEL::LV_TRACE));

		try
		{
			std::unique_ptr<VIIL::Application, VIIL::ApplicationDeleter> application = VIIL::createApplication();

			application->run();

			VL_ENGINE_TRACE("Post run.");
		}
		catch (std::exception e)
		{
			returnCode = -1;
			VL_ENGINE_FATAL(e.what());
		}
	}

	return returnCode;
}

#endif