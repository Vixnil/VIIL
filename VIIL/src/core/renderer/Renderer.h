#pragma once
#include "standardUse.h"

namespace VIIL
{

	enum class RendererType
	{
		None = 0,
		OpenGL
	};

	class Renderer
	{
		static RendererType type;
	public:

		inline static RendererType getType() { return type; }
	};

}
