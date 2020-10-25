#include "standardUse.h"
#include "Shader.h"
#include "RendererLibrary.h"
#include "core/renderer/OpenGL/OpenGLShader.h"

namespace VIIL
{

	std::shared_ptr<Shader> Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (RendererLibrary::getType())
		{
		case RendererLibrary::Type::OpenGL:
			return std::shared_ptr<Shader>(new OpenGLShader(vertexSrc, fragmentSrc));
			break;
		default:
			VL_ENGINE_FATAL("Unimplemented renderer type selected. Shader creation failed.");
		}

		return nullptr;
	}

}