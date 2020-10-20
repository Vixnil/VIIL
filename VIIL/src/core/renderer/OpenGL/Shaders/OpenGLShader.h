#pragma once
#include "standardUse.h"
#include "core/renderer/Shader.h"

namespace VIIL
{

	class OpenGLShader : public Shader
	{
		uint32_t rengererId;
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;
	};

}
