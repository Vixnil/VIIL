#include "standardUse.h"
#include "IndexBuffer.h"
#include "core/renderer/OpenGL/Buffers/OpenGLIndexBuffer.h"

namespace VIIL
{

	std::unique_ptr<IndexBuffer> IndexBuffer::Create(uint32_t* indicies, uint32_t size)
	{
		VL_ENGINE_TRACE("IndexBuffer creation.");

		switch (Renderer::getType())
		{
		case RendererType::OpenGL:
			return std::unique_ptr<IndexBuffer>(new OpenGLIndexBuffer(indicies, size));
			break;
		default:
			VL_ENGINE_FATAL("Unimplemented renderer type selected. Index buffer creation failed.");
		}

		return nullptr;
	}
}