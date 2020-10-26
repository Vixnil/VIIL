#pragma once
#include "core/standardUse.h"
#include "platform/interface/Clock.h"

namespace VIIL
{

	class WindowsClock : public Clock
	{
	public:

		virtual float getCurrentTime() override;
		virtual float getTimeInSeconds() override;
		virtual float getTimeInMilliseconds() override;
	};

	static std::unique_ptr<Clock> createClock()
	{
		return std::make_unique<WindowsClock>();
	}
}
