#pragma once
#include "standardUse.h"
#include "RendererAction.h"

namespace VIIL
{

	class Renderer
	{
		static RendererLibrary::Type type;
	public:

		static void startScence() 
		{}

		static void endScence() 
		{}

		static void submit(const std::shared_ptr<VertexArray>& vertexArray) 
		{
			vertexArray->bind();
			RendererAction::draw(vertexArray);
		}

		inline static RendererLibrary::Type getType() { return type; }
	};

}
