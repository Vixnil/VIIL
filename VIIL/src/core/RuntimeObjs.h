#pragma once

#include "standardUse.h"
#include "Graphics.h"

namespace VIIL
{
	struct RuntimeObjs
	{
		std::unique_ptr<VIIL::Graphics> g;

		RuntimeObjs()
		{

		}

	};
}