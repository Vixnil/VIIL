#pragma once
#include "core/standardUse.h"
#include "renderer/interface/Shader.h"

namespace VIIL
{

	class OpenGLShader : public Shader
	{
		uint32_t shaderId;
		std::string name;
	public:
		OpenGLShader(const std::shared_ptr<File>& shaderSrc);
		OpenGLShader(const std::string& name, const std::shared_ptr<File>& vertexFile, const std::shared_ptr<File>& fragmentFile);
		OpenGLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
		~OpenGLShader();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual std::string getName() const override;

		virtual void setUniformInt(const std::string& uniformName, int& vp) override;

		virtual void setUniformFloat(const std::string& uniformName, float& vp) override;
		virtual void setUniformFloat2(const std::string& uniformName, glm::vec2& vp) override;
		virtual void setUniformFloat3(const std::string& uniformName, glm::vec3& vp) override;
		virtual void setUniformFloat4(const std::string& uniformName, glm::vec4& vp) override;

		virtual void setUniformMatrix3(const std::string& uniformName, glm::mat3& vp) override;
		virtual void setUniformMatrix4(const std::string& uniformName, glm::mat4& vp) override;
	};

}
