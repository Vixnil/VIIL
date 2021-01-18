#include "core/standardUse.h"
#include "platform/windows/WindowsClock.h"
#include "renderer/OpenGL/OpenGLInclude.h"

namespace VIIL
{
	/*
	* TODO: This should not use OpenGL to get system time
	* since eventually VIIL should be able to support platform specific
	* graphics API and OpenGL may not be used, which should not break the Clock class.
	*/
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