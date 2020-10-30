#include "core/standardUse.h"
#include "renderer/ShaderLibrary.h"

namespace VIIL
{

	void ShaderLibrary::add(const std::string& name, const std::shared_ptr<Shader>& shader)
	{
		if (get(name) == nullptr)
		{
			shaderMap[name] = shader;
		}
		else
		{
			VL_ENGINE_WARN("Attempt to add shader failed since provided name already exists: {0}", name);
		}
	}

	void ShaderLibrary::add(const std::shared_ptr<Shader>& shader)
	{
		add(shader->getName(), shader);
	}

	std::shared_ptr<Shader> ShaderLibrary::load(const std::string& name, const std::shared_ptr<File>& shaderFile)
	{
		add(name, Shader::Create(shaderFile));
		return get(name);
	}

	bool ShaderLibrary::exists(const std::string& name)
	{
		return (shaderMap.at(name) == nullptr);
	}

	std::shared_ptr<Shader> ShaderLibrary::get(const std::string& name)
	{
		return shaderMap[name];
	}

}