#include "standardUse.h"
#include "VertexArray.h"
#include "OpenGL/OpenGLVertexArray.h"

namespace VIIL
{
	std::unique_ptr<VertexArray> VertexArray::Create(uint32_t count, uint32_t size)
	{
		switch (Renderer::getType())
		{
		case RendererType::OpenGL:
			return std::unique_ptr<VertexArray>(new OpenGLVertexArray(count, size));
			break;
		default:
			VL_ENGINE_FATAL("Unimplemented renderer type selected. Vertex array creation failed.");
		}

		return nullptr;
	}
}