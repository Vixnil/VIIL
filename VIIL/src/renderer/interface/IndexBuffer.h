#pragma once
#include "core/standardUse.h"

namespace VIIL
{

	/*
	* Platform/Rendering API independent index buffer.
	* TODO: Might not be needed or may need to be reworked when more than just
	* OpenGL is implemented as DirectX does not use the concept of index buffers.
	*/
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

		static std::shared_ptr<IndexBuffer> Create(uint32_t* indicies, uint32_t size);
	};

}