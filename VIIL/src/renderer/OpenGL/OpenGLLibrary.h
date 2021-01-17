#pragma once
#include "core/standardUse.h"
#include "renderer/interface/RendererLibrary.h"

namespace VIIL
{

	class OpenGLLibrary : public RendererLibrary
	{
		virtual void setClearColor(const glm::vec4& color) override;
		virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
		virtual void clear() override;

		virtual void drawVertexArray(const std::shared_ptr<VertexArray>& vertexArray) override;
	};

}