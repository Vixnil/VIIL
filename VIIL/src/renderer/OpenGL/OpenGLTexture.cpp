#include "core/standardUse.h"
#include "renderer/OpenGL/OpenGLTexture.h"
#include "renderer/OpenGL/OpenGLInclude.h"

namespace VIIL
{
	OpenGLTexture2D::OpenGLTexture2D(std::string path)
	{
		int w = -1, h = -1, channels = -1;
		int glStoreFlag = -1, glDataFlag = -1;
		unsigned char* imageMap;
		
		stbi_set_flip_vertically_on_load(true);
		imageMap = stbi_load(path.c_str(), &w, &h, &channels, 0);
		
		width = w;
		height = h;

		if (channels == 3)
		{
			glStoreFlag = GL_RGB8;
			glDataFlag = GL_RGB;
		}
		else if (channels == 4)
		{
			glStoreFlag = GL_RGBA8;
			glDataFlag = GL_RGBA;
		}
		else
		{
			VL_ENGINE_ERROR("Texture2d failed to load: {0}", path);
			return;
			stbi_image_free(imageMap);
		}

		glCreateTextures(GL_TEXTURE_2D, 1, &textureId);
		glTextureStorage2D(textureId, 1, glStoreFlag, width, height);

		glTextureParameteri(textureId, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(textureId, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureSubImage2D(textureId, 0, 0, 0, width, height, glDataFlag, GL_UNSIGNED_BYTE, imageMap);

		stbi_image_free(imageMap);
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &textureId);
	}

	void OpenGLTexture2D::bind(uint32_t textureSlot) const
	{
		glBindTextureUnit(textureSlot, textureId);
	}
}