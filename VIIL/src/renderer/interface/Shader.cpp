#include "core/standardUse.h"
#include "renderer/interface/Shader.h"
#include "renderer//interface/RendererLibrary.h"
#include "renderer/OpenGL/OpenGLShader.h"

namespace VIIL
{

	std::shared_ptr<Shader> Shader::Create(const std::shared_ptr<File>& shaderSrc)
	{
		switch (RendererLibrary::getType())
		{
		case RendererLibrary::Type::OpenGL:
			return std::shared_ptr<Shader>(new OpenGLShader(shaderSrc));
			break;
		default:
			VL_ENGINE_FATAL("Unimplemented renderer type selected. Shader creation failed.");
		}

		return nullptr;
	}

	std::shared_ptr<Shader> Shader::Create(const std::string& name, const std::shared_ptr<File>& vertexFile, const std::shared_ptr<File>& fragmentFile)
	{
		switch (RendererLibrary::getType())
		{
		case RendererLibrary::Type::OpenGL:
			return std::shared_ptr<Shader>(new OpenGLShader(name, vertexFile, fragmentFile));
			break;
		default:
			VL_ENGINE_FATAL("Unimplemented renderer type selected. Shader creation failed.");
		}

		return nullptr;
	}

	std::shared_ptr<Shader> Shader::Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (RendererLibrary::getType())
		{
		case RendererLibrary::Type::OpenGL:
			return std::shared_ptr<Shader>(new OpenGLShader(name, vertexSrc, fragmentSrc));
			break;
		default:
			VL_ENGINE_FATAL("Unimplemented renderer type selected. Shader creation failed.");
		}

		return nullptr;
	}

}