#pragma once
#include "standardUse.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"

namespace VIIL
{

	class VertexArray
	{
	public:
		using VertexBufferList = std::vector<std::shared_ptr<VertexBuffer>>;

		virtual ~VertexArray()
		{
			VL_ENGINE_TRACE("Default vertex array destructor.");
		};

		virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vBuffer) = 0;
		virtual void setIndexBuffer(const std::shared_ptr<IndexBuffer>& iBuffer) = 0;

		virtual const VertexBufferList& getVertexBuffers() const = 0;
		virtual const std::shared_ptr<IndexBuffer>& getIndexBuffer() const = 0;

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		static std::shared_ptr<VertexArray> Create();
	};

}
