#pragma once

#include "standardUse.h"
#include "core/renderer/interface/VertexArray.h"
#include "OpenGLInclude.h"

namespace VIIL
{

	class OpenGLVertexArray : public VertexArray
	{
		VertexBufferList vertexBufferList;
		std::shared_ptr<IndexBuffer> indexBuffer;
		uint32_t vertexArray;

	public:
		OpenGLVertexArray();
		~OpenGLVertexArray();

		virtual const VertexBufferList& getVertexBuffers() const override;
		virtual const std::shared_ptr<IndexBuffer>& getIndexBuffer() const override;
		virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vBuffer) override;
		virtual void setIndexBuffer(const std::shared_ptr<IndexBuffer>& iBuffer) override;
		virtual void bind() const override;
		virtual void unbind() const override;
	};

}
