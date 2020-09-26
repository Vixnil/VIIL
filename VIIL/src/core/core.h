#pragma once

#ifdef VIIL_PLATFORM_WINDOWS
	#ifdef VIIL_BUILD_DLL
		#define VIIL_API __declspec(dllexport)
	#else
		#define VIIL_API __declspec(dllimport)
	#endif

	#include "core/platform/windows/WindowsGraphics.h"
	#define VIIL_PLATFORM_GRAPHICS VIIL::WindowsGraphics::initializeGraphics()
#else
	#error BuildFailed: Unsupported platform
#endif

#define BIT(x) (1 << x)