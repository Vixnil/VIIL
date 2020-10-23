#include "standardUse.h"
#include "VertexArray.h"
#include "RendererLibrary.h"
#include "core/renderer/OpenGL/OpenGLVertexArray.h"

namespace VIIL
{
	std::shared_ptr<VertexArray> VertexArray::Create()
	{
		switch (RendererLibrary::getType())
		{
		case RendererLibrary::Type::OpenGL:
			return std::shared_ptr<VertexArray>(new OpenGLVertexArray());
			break;
		default:
			VL_ENGINE_FATAL("Unimplemented renderer type selected. Vertex array creation failed.");
		}

		return nullptr;
	}
}