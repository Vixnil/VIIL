#include "core/standardUse.h"
#include "renderer/interface/RendererLibrary.h"
#include "renderer/OpenGL/OpenGLLibrary.h"

namespace VIIL
{
	RendererLibrary::Type RendererLibrary::libraryType = RendererLibrary::Type::OpenGL;
}