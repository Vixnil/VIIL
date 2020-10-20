#include "standardUse.h"
#include "Shader.h"
#include "OpenGL/Shaders/OpenGLShader.h"

namespace VIIL
{

	std::unique_ptr<Shader> Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::getType())
		{
		case RendererType::OpenGL:
			return std::unique_ptr<Shader>(new OpenGLShader(vertexSrc, fragmentSrc));
			break;
		default:
			VL_ENGINE_FATAL("Unimplemented renderer type selected. Shader creation failed.");
		}

		return nullptr;
	}

}