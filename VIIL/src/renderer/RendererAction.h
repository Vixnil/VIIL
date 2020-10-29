#pragma once
#include "core/standardUse.h"
#include "renderer/interface/RendererLibrary.h"

namespace VIIL
{

	class RendererAction
	{
		static std::unique_ptr<RendererLibrary> rendererLib;

	public:

		inline static void setClearColor(glm::vec4 color)
		{
			rendererLib->setClearColor(color);
		}

		inline static void clear()
		{
			rendererLib->clear();
		}

		inline static void draw(const std::shared_ptr<VertexArray>& vertexArray)
		{
			rendererLib->drawVertexArray(vertexArray);
		}
	};

}
