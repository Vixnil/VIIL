#pragma once
#include "core/standardUse.h"

namespace VIIL
{

	/*
	* Platform independent class to allow getting of system time and similar
	* time based api.
	*/
	class Clock
	{
	public:

		virtual float getCurrentTime() = 0;
		virtual float getTimeInSeconds() = 0;
		virtual float getTimeInMilliseconds() = 0;
	};

	static std::unique_ptr<Clock> createClock();
}
