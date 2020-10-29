#pragma once
#include "core/standardUse.h"
#include "renderer/interface/Texture.h"

namespace VIIL
{

	class OpenGLTexture2D : public Texture2D
	{
		uint32_t textureId;
		uint32_t width, height;
	public:
		OpenGLTexture2D(std::string path);
		virtual ~OpenGLTexture2D();

		virtual uint32_t getWidth() const override { return width; };
		virtual uint32_t getHeight() const override { return height; };

		virtual void bind(uint32_t textureSlot = 0) const override;
	};

}
