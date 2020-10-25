#include "standardUse.h"
#include "OpenGLShader.h"
#include "core/renderer/OpenGL/OpenGLInclude.h"

#include <glm/gtc/type_ptr.hpp>

namespace VIIL
{

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

	OpenGLShader::OpenGLShader(const std::string& vertexSrc, const std::string& fragmentSrc):
		shaderId(0)
	{
		unsigned int vertexShader = compileShader(GL_VERTEX_SHADER, vertexSrc);

		if (vertexShader)
		{
			unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSrc);

			if (fragmentShader)
			{
				int isLinked = 0;
				shaderId = glCreateProgram();
				glAttachShader(shaderId, vertexShader);
				glAttachShader(shaderId, fragmentShader);
				glLinkProgram(shaderId);
				glGetProgramiv(shaderId, GL_LINK_STATUS, (int*)&isLinked);

				if (isLinked == GL_FALSE)
				{
					GLint maxLength = 0;

					glGetProgramiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);

					std::vector<GLchar> infoLog(maxLength);
					glGetProgramInfoLog(shaderId, maxLength, &maxLength, &infoLog[0]);
					glDeleteProgram(shaderId);
					glDeleteShader(vertexShader);
					glDeleteShader(fragmentShader);

					VL_ENGINE_ERROR("Shader program linkage failed!");
					VL_ENGINE_ERROR("     {0}", infoLog.data());
				}
				else
				{
					glDetachShader(shaderId, vertexShader);
					glDetachShader(shaderId, fragmentShader);

					VL_ENGINE_TRACE("OpenGL Shader constructed.");
				}
			}
		}
	}

	OpenGLShader::~OpenGLShader()
	{
		glDeleteProgram(shaderId);
		VL_ENGINE_TRACE("OpenGL Shader destoyed.");
	}

	void OpenGLShader::setUniformMatrix4(glm::mat4& vp, const std::string& uniformName)
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