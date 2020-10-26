#include "core/standardUse.h"
#include "platform/windows/WindowsClock.h"
#include "renderer/OpenGL/OpenGLInclude.h"

namespace VIIL
{

	float WindowsClock::getCurrentTime()
	{
		return (float)glfwGetTime();
	}

	float WindowsClock::getTimeInSeconds()
	{
		return getCurrentTime();
	}

	float WindowsClock::getTimeInMilliseconds()
	{
		return getTimeInSeconds() * 1000;
	}

}