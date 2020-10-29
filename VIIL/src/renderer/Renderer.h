#pragma once
#include "core/standardUse.h"
#include "platform/interface/Window.h"

#include "renderer/Scene.h"
#include "renderer/RendererAction.h"

#include <glm/glm.hpp>

namespace VIIL
{
	class Renderer
	{
		static RendererLibrary::Type type;
		static Renderer theRenderer;

		std::shared_ptr<Window> appWindow;

		Renderer(std::shared_ptr<Window> window) :
			appWindow(window)
		{}

	public:
		static void set(std::shared_ptr<Window> appWindow)
		{
			if (!theRenderer.appWindow)
			{
				theRenderer = Renderer(appWindow);
			}
		}

		Renderer() = delete;

		float getCurrentAspectRatio()
		{
			return (float)appWindow->getHeight() / (float)appWindow->getWidth();
		}

		static void drawScene(Scene& scene)
		{
			std::vector<SceneObjects> sceneVec = scene.getObjectsInScene();
			//sort so all shaders are paired together, to bind once then do all vArray drawing before moving to next shader
			for (SceneObjects obj : sceneVec)
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

		static inline RendererLibrary::Type getType() { return type; }
		static Renderer& get() { return theRenderer; }
	};

}
