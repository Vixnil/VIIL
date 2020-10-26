#pragma once
#include "core/standardUse.h"
#include "renderer/interface/Shader.h"

namespace VIIL
{

	class OpenGLShader : public Shader
	{
		uint32_t shaderId;
	public:
		OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;
		virtual void setUniformMatrix4(glm::mat4& vp, const std::string& uniformName) override;
	};

}
