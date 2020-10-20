#pragma once

#include "standardUse.h"
#include "Renderer.h"

namespace VIIL
{

	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() 
		{
			VL_ENGINE_TRACE("Default index buffer destructor.");
		};

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		virtual uint32_t count() const = 0;

		static std::unique_ptr<IndexBuffer> Create(uint32_t* indicies, uint32_t size);
	};

}