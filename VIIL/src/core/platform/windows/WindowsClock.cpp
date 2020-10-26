#include "standardUse.h"
#include "WindowsClock.h"

#include "core/renderer/OpenGL/OpenGLInclude.h"

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