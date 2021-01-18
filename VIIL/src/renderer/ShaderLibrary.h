#pragma once
#include "core/standardUse.h"
#include "renderer/interface/Shader.h"

namespace VIIL
{
	/*
	* Wrapper for a map of shaders to be loaded and reused on demand.
	* Allows developers to load shaders once as needed and they will stay in
	* memory until the application is done.
	*/
	class ShaderLibrary
	{
		std::unordered_map <std::string, std::shared_ptr<Shader>> shaderMap;

	public:
		void add(const std::shared_ptr<Shader>& shader);
		void add(const std::string& name, const std::shared_ptr<Shader>& shader);

		std::shared_ptr<Shader> load(const std::string& name, const std::shared_ptr<File>& shaderFile);
		std::shared_ptr<Shader> get(const std::string& name);

		bool exists(const std::string& name);
	};
}