#pragma once

#include "InitializationServices.h"

#ifdef VIIL_PLATFORM_WINDOWS

extern VIIL::Application* VIIL::createApplication();

int main(int argc, char** argv)
{
	auto application = VIIL::createApplication();

	InitializeEngine(application);

	application->run();
	delete application;
}

#endif