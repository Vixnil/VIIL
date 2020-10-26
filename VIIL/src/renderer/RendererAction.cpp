#include "core/standardUse.h"
#include "renderer/RendererAction.h"
#include "renderer/OpenGL/OpenGLLibrary.h"

namespace VIIL
{
	std::unique_ptr<RendererLibrary> RendererAction::rendererLib = std::make_unique<OpenGLLibrary>();
}