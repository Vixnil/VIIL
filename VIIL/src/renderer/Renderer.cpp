#include "core/standardUse.h"
#include "renderer/Renderer.h"
#include "renderer/interface/RendererLibrary.h"

namespace VIIL
{
	RendererLibrary::Type Renderer::type = RendererLibrary::Type::OpenGL;
	Renderer Renderer::theRenderer = 0;
}