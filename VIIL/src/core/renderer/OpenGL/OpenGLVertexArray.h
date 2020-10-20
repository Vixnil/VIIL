#pragma once

#include "standardUse.h"
#include "core/renderer/VertexArray.h"
#include "OpenGLInclude.h"

namespace VIIL
{

	class OpenGLVertexArray : public VertexArray
	{
		uint32_t vertexArray;

	public:
		OpenGLVertexArray(uint32_t count, uint32_t size);
		~OpenGLVertexArray();

		virtual void bind() const override;
		virtual void unbind() const override;
	};

}
