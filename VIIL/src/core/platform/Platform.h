#pragma once
#include "standardUse.h"
#include "interface/Clock.h"
#include "windows/WindowsClock.h"

namespace VIIL
{
	class Platform
	{
		std::unique_ptr<Clock> platformClock;
		static std::unique_ptr<Platform> plat;

	public:

		Platform():
			platformClock(createClock())
		{}

		static std::unique_ptr<Platform>& get() { return plat; }

		std::unique_ptr<Clock>& getClock() { return platformClock; }
	};

}

