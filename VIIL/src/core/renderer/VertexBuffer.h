#pragma once

#include "standardUse.h"
#include "Renderer.h"

namespace VIIL
{

	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() 
		{
			VL_ENGINE_TRACE("Default vertext buffer destructor.");
		};

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		static std::unique_ptr<VertexBuffer> Create(float* vertices, uint32_t size);

	};

}
