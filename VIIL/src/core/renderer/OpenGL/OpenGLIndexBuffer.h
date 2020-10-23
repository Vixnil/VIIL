#pragma once

#include "standardUse.h"
#include "core/renderer/interface/IndexBuffer.h"

namespace VIIL
{

	class OpenGLIndexBuffer : public IndexBuffer
	{
		uint32_t bufferId;
		uint32_t numIndicies;

	public:

		OpenGLIndexBuffer(uint32_t* indicies, uint32_t size);

		virtual ~OpenGLIndexBuffer();

		virtual uint32_t count() const override { return numIndicies; };
		virtual void bind() const override;
		virtual void unbind() const override;
	};

}