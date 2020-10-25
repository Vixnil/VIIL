#pragma once
#include "standardUse.h"
#include "RendererAction.h"

namespace VIIL
{

	class Renderer
	{
		static RendererLibrary::Type type;
	public:

		static void drawScene(Scene& scene)
		{
			auto sceneVec = scene.getObjectsInScene();

			//sort so all shaders are paired together, to bind once then do all vArray drawing before moving to next shader
			for (auto obj : sceneVec)
			{
				obj.shader->Bind();
				obj.vArray->bind();
				RendererAction::draw(obj.vArray);
				obj.vArray->unbind();
				obj.shader->Unbind();
			}

		}

		static void submit(const std::shared_ptr<VertexArray>& vertexArray) 
		{
			vertexArray->bind();
			RendererAction::draw(vertexArray);
		}

		inline static RendererLibrary::Type getType() { return type; }
	};

}
