#include "standardUse.h"
#include "OpenGLLibrary.h"
#include "OpenGLInclude.h"

namespace VIIL
{
	void OpenGLLibrary::setClearColor(const glm::vec4& color)
	{
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLLibrary::clear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLLibrary::drawVertexArray(const std::shared_ptr<VertexArray>& vertexArray)
	{
		glDrawElements(GL_TRIANGLES, vertexArray->getIndexBuffer()->count(), GL_UNSIGNED_INT, nullptr);
	}
}