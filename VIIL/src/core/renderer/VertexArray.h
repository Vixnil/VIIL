#pragma once
#include "standardUse.h"
#include "Renderer.h"

namespace VIIL
{

	class VertexArray
	{
	public:
		virtual ~VertexArray()
		{
			VL_ENGINE_TRACE("Default vertext array destructor.");
		};

		virtual void bind() const = 0;
		virtual void unbind() const = 0;

		static std::unique_ptr<VertexArray> Create(uint32_t count, uint32_t size);

	};

}
