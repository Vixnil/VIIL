#pragma once
#include "standardUse.h"
#include "core/renderer/VertexBuffer.h"

namespace VIIL
{
	class OpenGLVertexBuffer : public VertexBuffer
	{
		uint32_t bufferId;

	public:

		OpenGLVertexBuffer(float* vertices, uint32_t size);

		virtual ~OpenGLVertexBuffer() override;

		virtual void bind() const override;
		virtual void unbind() const override;
	};
}
