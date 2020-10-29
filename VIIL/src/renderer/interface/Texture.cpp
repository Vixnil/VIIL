#include "core/standardUse.h"
#include "renderer/interface/Texture.h"
#include "renderer/interface/RendererLibrary.h"
#include "renderer/OpenGL/OpenGLTexture.h"

namespace VIIL
{
	std::shared_ptr<Texture2D> Texture2D::create(std::string path)
	{
		VL_ENGINE_TRACE("Texture2D creation.");

		switch (RendererLibrary::getType())
		{
		case RendererLibrary::Type::OpenGL:
			return std::shared_ptr<Texture2D>(new OpenGLTexture2D(path));
			break;
		default:
			VL_ENGINE_FATAL("Unimplemented renderer type selected. Texture 2D creation failed.");
		}

		return nullptr;
	}
}