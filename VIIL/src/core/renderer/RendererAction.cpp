#include "standardUse.h"
#include "RendererAction.h"
#include "OpenGL/OpenGLLibrary.h"

namespace VIIL
{
	std::unique_ptr<RendererLibrary> RendererAction::rendererLib = std::make_unique<OpenGLLibrary>();
}