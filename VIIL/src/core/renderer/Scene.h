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

		void setObjectToScene(std::shared_ptr<Shader> shader, std::shared_ptr<VertexArray> vArray)
		{ 
			shader->setUniformMatrix4(viewProjection, "vpMatrix");
			toRenderList.push_back({shader, vArray}); 
		}

		inline std::vector<SceneObjects>& getObjectsInScene() { return toRenderList; }

		~Scene()
		{}
	};

}
