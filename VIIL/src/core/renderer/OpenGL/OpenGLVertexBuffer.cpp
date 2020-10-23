#include "standardUse.h"
#include "OpenGLVertexBuffer.h"
#include "core/renderer/OpenGL/OpenGLInclude.h"

namespace VIIL
{

	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
	{
		glGenBuffers(1, &bufferId);
		glBindBuffer(GL_ARRAY_BUFFER, bufferId);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		VL_ENGINE_TRACE("OpenGL VertexBuffer constructed");
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &bufferId);
		VL_ENGINE_TRACE("OpenGL VertexBuffer destroyed");
	}

	void OpenGLVertexBuffer::bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, bufferId);
	}

	void OpenGLVertexBuffer::unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}