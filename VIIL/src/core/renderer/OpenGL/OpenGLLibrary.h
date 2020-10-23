#pragma once
#include "standardUse.h"
#include "core/renderer/interface/RendererLibrary.h"

namespace VIIL
{

	class OpenGLLibrary : public RendererLibrary
	{
		virtual void setClearColor(const glm::vec4& color) override;
		virtual void clear() override;

		virtual void drawVertexArray(const std::shared_ptr<VertexArray>& vertexArray) override;
	};

}