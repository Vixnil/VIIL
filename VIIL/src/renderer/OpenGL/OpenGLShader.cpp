#include "core/standardUse.h"
#include "renderer/OpenGL/OpenGLShader.h"
#include "renderer/OpenGL/OpenGLInclude.h"

#include <glm/gtc/type_ptr.hpp>

namespace VIIL
{

	enum ShaderType : GLenum
	{
		vertex = GL_VERTEX_SHADER,
		fragment = GL_FRAGMENT_SHADER
	};

	struct ShaderInfo
	{
		const std::string source;
		ShaderType type;
	};

	std::string glfwShaderIntToTextName(unsigned int shaderType)
	{
		std::string message = "";

		switch (shaderType)
		{
		case GL_VERTEX_SHADER:
			message = "Vertex";
			break;
		case GL_FRAGMENT_SHADER:
			message = "Fragment";
			break;
		default:
			message = "UNKNOWN TYPE";
			break;
		}

		return message;
	}

	unsigned int compileShader(unsigned int shaderType, const std::string& source)
	{
		unsigned int shader = glCreateShader(shaderType);
		const char* src = source.c_str();
		int isCompiled = 0;

		glShaderSource(shader, 1, &src, 0);
		glCompileShader(shader);
		glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);

		if (isCompiled == GL_FALSE)
		{
			int maxLength = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> infoLog(maxLength);
			glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);
			glDeleteShader(shader);

			VL_ENGINE_ERROR("{0} Shader compiliation failed!", glfwShaderIntToTextName(shaderType));
			VL_ENGINE_ERROR("     {0}", infoLog.data());

			return 0;
		}

		return shader;
	}

	uint32_t compileProgram(const std::vector<ShaderInfo>& shaderList)
	{
		uint32_t shaderId = 0;
		std::vector<unsigned int> shaderIdList;
		bool failed = false;

		shaderIdList.reserve(shaderList.size());

		for (ShaderInfo info : shaderList)
		{
			unsigned int shaderId = compileShader(info.type, info.source);

			if (!shaderId)
			{
				failed = true;
				break;
			}

			shaderIdList.push_back(shaderId);
		}

		if (!failed)
		{
			int isLinked = 0;
			shaderId = glCreateProgram();

			for(unsigned int id : shaderIdList)
				glAttachShader(shaderId, id);

			glLinkProgram(shaderId);
			glGetProgramiv(shaderId, GL_LINK_STATUS, (int*)&isLinked);

			if (isLinked == GL_FALSE)
			{
				GLint maxLength = 0;

				glGetProgramiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetProgramInfoLog(shaderId, maxLength, &maxLength, &infoLog[0]);
				glDeleteProgram(shaderId);

				for (unsigned int id : shaderIdList)
					glDeleteShader(id);

				VL_ENGINE_ERROR("Shader program linkage failed!");
				VL_ENGINE_ERROR("     {0}", infoLog.data());
			}
			else
			{
				for (unsigned int id : shaderIdList)
					glDetachShader(shaderId, id);

				VL_ENGINE_TRACE("OpenGL Shader constructed.");
			}
		}

		return shaderId;
	}

	OpenGLShader::OpenGLShader(const std::shared_ptr<File>& vertexFile, const std::shared_ptr<File>& fragmentFile):
		shaderId(0)
	{
		std::vector<ShaderInfo> shaders;
		shaders.push_back({ vertexFile->readFileToString(), ShaderType::vertex });
		shaders.push_back({ fragmentFile->readFileToString(), ShaderType::fragment });
		shaderId = compileProgram(shaders);
	}

	OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc):
		shaderId(0)
	{
		std::vector<ShaderInfo> shaders;
		shaders.push_back({ vertexSrc, ShaderType::vertex });
		shaders.push_back({ fragmentSrc, ShaderType::fragment });
		shaderId = compileProgram(shaders);
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(shaderId);
		VL_ENGINE_TRACE("OpenGL Shader destoyed.");
	}

	void OpenGLShader::setUniformInt(const std::string& uniformName, int& vp)
	{
		Bind();
		int loc = glGetUniformLocation(shaderId, uniformName.c_str());

		if (loc != -1)
		{
			glUniform1i(loc, vp);
		}
		Unbind();
	}

	void OpenGLShader::setUniformFloat(const std::string& uniformName, float& vp)
	{
		Bind();
		int loc = glGetUniformLocation(shaderId, uniformName.c_str());

		if (loc != -1)
		{
			glUniform1f(loc, vp);
		}
		Unbind();
	}

	void OpenGLShader::setUniformFloat2(const std::string& uniformName, glm::vec2& vp)
	{
		Bind();
		int loc = glGetUniformLocation(shaderId, uniformName.c_str());

		if (loc != -1)
		{
			glUniform2f(loc, vp.x, vp.y);
		}
		Unbind();
	}

	void OpenGLShader::setUniformFloat3(const std::string& uniformName, glm::vec3& vp)
	{
		Bind();
		int loc = glGetUniformLocation(shaderId, uniformName.c_str());

		if (loc != -1)
		{
			glUniform3f(loc, vp.x, vp.y, vp.z);
		}
		Unbind();
	}

	void OpenGLShader::setUniformFloat4(const std::string& uniformName, glm::vec4& vp)
	{
		Bind();
		int loc = glGetUniformLocation(shaderId, uniformName.c_str());

		if (loc != -1)
		{
			glUniform4f(loc, vp.x, vp.y, vp.z, vp.a);
		}
		Unbind();
	}

	void OpenGLShader::setUniformMatrix3(const std::string& uniformName, glm::mat3& vp)
	{
		Bind();
		int loc = glGetUniformLocation(shaderId, uniformName.c_str());

		if (loc != -1)
		{
			glUniformMatrix3fv(loc, 1, GL_FALSE, glm::value_ptr(vp));
		}
		Unbind();
	}

	void OpenGLShader::setUniformMatrix4(const std::string& uniformName, glm::mat4& vp)
	{
		Bind();
		int loc = glGetUniformLocation(shaderId, uniformName.c_str());

		if (loc != -1)
		{
			glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(vp));
		}
		Unbind();
	}

	void OpenGLShader::Bind() const
	{
		glUseProgram(shaderId);
	}

	void OpenGLShader::Unbind() const
	{
		glUseProgram(0);
	}
}