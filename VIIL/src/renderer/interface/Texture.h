#pragma once
#include "core/standardUse.h"

namespace VIIL
{
	class Texture
	{
	public:
		virtual ~Texture() = default;
		virtual uint32_t getWidth() const = 0;
		virtual uint32_t getHeight() const = 0;

		virtual void bind(uint32_t textureSlot) const = 0;
	};

	class Texture2D : public Texture
	{
	public:
		virtual ~Texture2D() = default;
		static std::shared_ptr<Texture2D> create(const std::string path);
	};
}