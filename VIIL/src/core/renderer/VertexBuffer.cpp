#include "standardUse.h"
#include "VertexBuffer.h"
#include "core/renderer/OpenGL/Buffers/OpenGLVertexBuffer.h"

namespace VIIL
{
	std::unique_ptr<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		VL_ENGINE_TRACE("VertexBuffer creation.");

		switch (Renderer::getType())
		{
		case RendererType::OpenGL:
			return std::unique_ptr<VertexBuffer>(new OpenGLVertexBuffer(vertices, size));
			break;
		default:
			VL_ENGINE_FATAL("Unimplemented renderer type selected. Vertex buffer creation failed.");
		}

		return nullptr;
	}
}