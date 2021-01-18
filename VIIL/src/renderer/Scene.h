#pragma once
#include "core/standardUse.h"
#include "renderer/Camera.h"
#include "renderer/CameraController.h"
#include "renderer/interface/Shader.h"
#include "renderer/interface/VertexArray.h"

namespace VIIL
{
	struct SceneObjects
	{
		std::shared_ptr<Shader> shader;
		std::shared_ptr<VertexArray> vArray;
	};

	/*
	* An object to keep track of all things getting ready to be rendered
	* and how they should be rendered. Allows for developers to store frequently needed
	* set views as a Scene object that just needs to be sent to the renderer to be rendered.
	*/
	class Scene
	{
		std::vector<SceneObjects> toRenderList;
		glm::mat4 viewProjection;
		float aspectRatio;

	public:
		Scene() = delete;

		Scene(CameraController& camControl) :
			viewProjection(camControl.getViewProjectionMatrix()), aspectRatio(camControl.getAspectRatio())
		{
		}

		Scene(Camera& cam):
			viewProjection(cam.getViewMatrix() * cam.getProjectionMatrix()), aspectRatio(cam.getAspectRatio())
		{
		}

		void setObjectToScene(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> vArray, glm::mat4& objectTransform = glm::mat4(1.0f))
		{ 
			shader->setUniformMatrix4("vpMatrix", viewProjection);
			shader->setUniformMatrix4("objTransformMatrix", objectTransform);
			shader->setUniformFloat("aspectRatio", aspectRatio);

			std::vector<std::shared_ptr<VertexBuffer>> list = vArray->getVertexBuffers();

			toRenderList.push_back({shader, vArray}); 
		}

		inline std::vector<SceneObjects>& getObjectsInScene() { return toRenderList; }

		~Scene()
		{}
	};

}
