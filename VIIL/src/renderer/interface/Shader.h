#pragma once
#include "core/standardUse.h"

#include <glm/glm.hpp>

namespace VIIL
{

	class Shader
	{
	public:
		~Shader() {};

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;
		virtual void setUniformMatrix4(glm::mat4& vp, const std::string& uniformName) = 0;

		static std::shared_ptr<Shader> Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};

}