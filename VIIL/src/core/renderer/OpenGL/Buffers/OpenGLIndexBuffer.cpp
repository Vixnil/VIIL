#include "standardUse.h"
#include "OpenGLIndexBuffer.h"
#include "core/renderer/OpenGL/OpenGLInclude.h"

namespace VIIL
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indicies, uint32_t size):
		numIndicies(size / sizeof(uint32_t))
	{
		glGenBuffers(1, &bufferId);
		bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indicies, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer() 
	{
		glDeleteBuffers(1, &bufferId);
	}

	void OpenGLIndexBuffer::bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
	}

	void OpenGLIndexBuffer::unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}