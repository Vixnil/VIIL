#pragma once

#include "standardUse.h"
#include "Graphics.h"

namespace VIIL
{
	struct RuntimeObjs
	{
		std::unique_ptr<VIIL::Graphics, VIIL::GraphicsDeleter> g;

		RuntimeObjs()
		{
			VL_ENGINE_TRACE("Initialized Runtimeobjs obj");
		}

		~RuntimeObjs()
		{
			VL_ENGINE_TRACE("Destroyed Runtimeobjs obj");
		}
	};
}