#pragma once
#include "standardUse.h"
#include "Camera.h"
#include "interface/Shader.h"
#include "interface/VertexArray.h"

namespace VIIL
{

	struct SceneObjects
	{
		std::shared_ptr<Shader> shader;
		std::shared_ptr<VertexArray> vArray;
	};

	class Scene
	{
		std::vector<SceneObjects> toRenderList;
		glm::mat4 viewProjection;

	public:
		Scene() = delete;

		Scene(Camera& cam):
			viewProjection(cam.getViewMatrix() * cam.getProjectionMatrix())
		{
		}

		void setObjectToScene(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> vArray, glm::mat4& objectTransform = glm::mat4(1.0f))
		{ 
			shader->setUniformMatrix4(viewProjection, "vpMatrix");
			shader->setUniformMatrix4(objectTransform, "objTransformMatrix");
			toRenderList.push_back({shader, vArray}); 
		}

		inline std::vector<SceneObjects>& getObjectsInScene() { return toRenderList; }

		~Scene()
		{}
	};

}
