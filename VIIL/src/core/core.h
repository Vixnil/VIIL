#pragma once

#ifdef VIIL_PLATFORM_WINDOWS
	#ifdef VIIL_BUILD_DLL
		#define VIIL_API __declspec(dllexport)
	#else
		#define VIIL_API __declspec(dllimport)
	#endif
#else
	#error BuildFailed: Unsupported platform
#endif