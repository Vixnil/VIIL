#pragma once

#include "standardUse.h"
#include "RuntimeObjs.h"
#include "InitializationServices.h"

#ifdef VIIL_PLATFORM_WINDOWS

extern std::unique_ptr<VIIL::Application> VIIL::createApplication();

int main(int argc, char** argv)
{
	int returnCode = 0;
	{
		std::unique_ptr<VIIL::RuntimeObjs> engineData = std::make_unique<VIIL::RuntimeObjs>();
		{
			std::unique_ptr<VIIL::Application> application;

			try
			{
				application = VIIL::createApplication();

				InitializeEngine(engineData.get(), application.get());

				application->run();
			}
			catch (std::exception e)
			{
				returnCode = -1;
				VL_ENGINE_FATAL(e.what());
			}
		}
	}

	return returnCode;
}

#endif