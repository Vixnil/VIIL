#pragma once
#include "core/standardUse.h"
#include "platform/interface/File.h"

#include <glm/glm.hpp>

namespace VIIL
{
	class Shader
	{
	public:
		~Shader() {};

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual std::string getName() const = 0;

		virtual void setUniformInt(const std::string& uniformName, int& vp) = 0;

		virtual void setUniformFloat(const std::string& uniformName, float& vp) = 0;
		virtual void setUniformFloat2(const std::string& uniformName, glm::vec2& vp) = 0;
		virtual void setUniformFloat3(const std::string& uniformName, glm::vec3& vp) = 0;
		virtual void setUniformFloat4(const std::string& uniformName, glm::vec4& vp) = 0;

		virtual void setUniformMatrix3(const std::string& uniformName, glm::mat3& vp) = 0;
		virtual void setUniformMatrix4(const std::string& uniformName, glm::mat4& vp) = 0;
		
		static std::shared_ptr<Shader> Create(const std::shared_ptr<File>& shaderSrc);
		static std::shared_ptr<Shader> Create(const std::string& name, const std::shared_ptr<File>& vertexFile, const std::shared_ptr<File>& fragmentFile);
		static std::shared_ptr<Shader> Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
	};

}