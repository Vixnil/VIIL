#include "standardUse.h"
#include "VertexBuffer.h"
#include "RendererLibrary.h"
#include "core/renderer/OpenGL/OpenGLVertexBuffer.h"

namespace VIIL
{
	std::shared_ptr<VertexBuffer> VertexBuffer::Create(float* vertices, uint32_t size)
	{
		VL_ENGINE_TRACE("VertexBuffer creation.");

		switch (RendererLibrary::getType())
		{
		case RendererLibrary::Type::OpenGL:
			return std::shared_ptr<VertexBuffer>(new OpenGLVertexBuffer(vertices, size));
			break;
		default:
			VL_ENGINE_FATAL("Unimplemented renderer type selected. Vertex buffer creation failed.");
		}

		return nullptr;
	}
}