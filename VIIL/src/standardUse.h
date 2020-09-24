#pragma once

#include <string>
#include <functional>
#include <sstream>
#include <memory>
#include <exception>

#ifdef VIIL_PLATFORM_WINDOWS
	#include <Windows.h>
	#include <GLFW/glfw3.h>
#endif

#include "core/core.h"
#include "core/event/event.h"
#include "core/Logger.h"
#include "core/Application.h"