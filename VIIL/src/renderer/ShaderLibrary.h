#pragma once
#include "core/standardUse.h"
#include "renderer/interface/Shader.h"

namespace VIIL
{

	class ShaderLibrary
	{
		std::unordered_map <std::string, std::shared_ptr<Shader>> shaders;

	public:
		void add(const std::shared_ptr<Shader>& shader);

		std::shared_ptr<Shader> load(const std::string& name, const std::string& filepath);

		std::shared_ptr<Shader> get(const std::string& name);
	};

}