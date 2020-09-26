#pragma once

#include "standardUse.h"
#include "RuntimeObjs.h"
#include "InitializationServices.h"

#ifdef VIIL_PLATFORM_WINDOWS

extern std::unique_ptr<VIIL::Application, VIIL::ApplicationDeleter> VIIL::createApplication();

int main(int argc, char** argv)
{
	int returnCode = 0;
	{
		VIIL::Logger::initEngineLogger(VIIL::LogConfig("VIIL", VIIL::Logger::defaultLogPattern, VIIL::LEVEL::LV_TRACE));

		std::unique_ptr<VIIL::RuntimeObjs> engineData = std::make_unique<VIIL::RuntimeObjs>();
		
		try
		{
			std::unique_ptr<VIIL::Application, VIIL::ApplicationDeleter> application = VIIL::createApplication();

			InitializeEngine(engineData.get(), application.get());

			application->run();
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