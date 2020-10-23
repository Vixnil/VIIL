#include "standardUse.h"
#include "OpenGLVertexArray.h"
#include "OpenGLVertexBuffer.h"

namespace VIIL
{
	OpenGLVertexArray::OpenGLVertexArray()
	{
		glGenVertexArrays(1, &vertexArray);
		VL_ENGINE_TRACE("OpenGL Vertex Array constructed");
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		VL_ENGINE_TRACE("OpenGL Vertex Array destroyed");
	}

	const OpenGLVertexArray::VertexBufferList& OpenGLVertexArray::getVertexBuffers() const
	{
		return vertexBufferList;
	}

	const std::shared_ptr<IndexBuffer>& OpenGLVertexArray::getIndexBuffer() const
	{
		return indexBuffer;
	}

	void OpenGLVertexArray::addVertexBuffer(const std::shared_ptr<VertexBuffer>& vBuffer)
	{
		if(vBuffer.get()->getLayout().getElements().size())
		{
			vertexBufferList.push_back(vBuffer);
			glBindVertexArray(vertexArray);
			vBuffer.get()->bind();

			uint32_t index = 0;
			const auto& myTriangleLayout = vBuffer.get()->getLayout();
			for (const auto& element : myTriangleLayout)
			{
				glEnableVertexAttribArray(index);
				glVertexAttribPointer(index,
					element.getTypeCount(),
					viilShaderDataTypeToGlfwDataType(element.type),
					element.isNormalized ? GL_TRUE : GL_FALSE,
					myTriangleLayout.getStride(),
					(const void*)element.offset);
				index++;
			}
			unbind();
			vBuffer.get()->unbind();
		}
		else
		{
			VL_ENGINE_ERROR("Attempted to add vertex buffer to vertex array failed, no layout defined in vertext buffer.");
		}
	}

	void OpenGLVertexArray::setIndexBuffer(const std::shared_ptr<IndexBuffer>& iBuffer)
	{
		indexBuffer = iBuffer;
		glBindVertexArray(vertexArray);
		iBuffer.get()->bind();
		unbind();
		iBuffer.get()->unbind();
	}

	void OpenGLVertexArray::bind() const
	{
		glBindVertexArray(vertexArray);
	}

	void OpenGLVertexArray::unbind() const
	{
		glBindVertexArray(0);
	}
}