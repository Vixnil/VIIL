#include "standardUse.h"
#include "IndexBuffer.h"
#include "RendererLibrary.h"
#include "core/renderer/OpenGL/OpenGLIndexBuffer.h"

namespace VIIL
{

	std::shared_ptr<IndexBuffer> IndexBuffer::Create(uint32_t* indicies, uint32_t size)
	{
		VL_ENGINE_TRACE("IndexBuffer creation.");

		switch (RendererLibrary::getType())
		{
		case RendererLibrary::Type::OpenGL:
			return std::shared_ptr<IndexBuffer>(new OpenGLIndexBuffer(indicies, size));
			break;
		default:
			VL_ENGINE_FATAL("Unimplemented renderer type selected. Index buffer creation failed.");
		}

		return nullptr;
	}
}