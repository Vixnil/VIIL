#pragma once
#include "standardUse.h"

namespace VIIL
{

	class Clock
	{
	public:

		virtual float getCurrentTime() = 0;
		virtual float getTimeInSeconds() = 0;
		virtual float getTimeInMilliseconds() = 0;
	};

	static std::unique_ptr<Clock> createClock();
}
