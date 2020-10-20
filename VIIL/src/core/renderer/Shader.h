#pragma once
#include "standardUse.h"
#include "Renderer.h"

namespace VIIL
{

	class Shader
	{
	public:
		~Shader() {};

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static std::unique_ptr<Shader> Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};

}