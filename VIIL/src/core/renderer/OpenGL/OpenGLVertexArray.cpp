#include "standardUse.h"
#include "OpenGLVertexArray.h"

namespace VIIL
{
	OpenGLVertexArray::OpenGLVertexArray(uint32_t count, uint32_t size)
	{
		glGenVertexArrays(1, &vertexArray);
		bind();
		glEnableVertexAttribArray(0);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{

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