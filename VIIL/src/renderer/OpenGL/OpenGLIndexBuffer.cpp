#include "core/standardUse.h"
#include "renderer/OpenGL/OpenGLIndexBuffer.h"
#include "renderer/OpenGL/OpenGLInclude.h"

namespace VIIL
{
	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indicies, uint32_t size):
		numIndicies(size / sizeof(uint32_t))
	{
		glGenBuffers(1, &bufferId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufferId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indicies, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		VL_ENGINE_TRACE("OpenGL IndexBuffer constructed");
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer() 
	{
		glDeleteBuffers(1, &bufferId);
		VL_ENGINE_TRACE("OpenGL IndexBuffer destroyed");
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