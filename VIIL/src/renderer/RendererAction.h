#pragma once
#include "core/standardUse.h"
#include "renderer/interface/RendererLibrary.h"

namespace VIIL
{

	class RendererAction
	{
		static std::unique_ptr<RendererLibrary> rendererLib;

	public:

		inline static void onWindowResize(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
		{
			rendererLib->setViewport(x, y, width, height);
		}

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
