#pragma once
#include "core/standardUse.h"
#include "platform/interface/Clock.h"
#include "platform/windows/WindowsClock.h"

namespace VIIL
{
	/*
	* Base class to be extended for each operating system VIIL supports
	*/
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

