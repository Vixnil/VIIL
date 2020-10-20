#pragma once

#define BIT(x) (1 << x)

#ifdef VIIL_PLATFORM_WINDOWS
#else
	#error BuildFailed: Unsupported platform
#endif
