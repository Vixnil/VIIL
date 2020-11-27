#pragma once
#include <VIIL.h>
#include <glm/gtc/matrix_transform.hpp>

class TestLayer : public VIIL::Layer
{
	VIIL::CameraOrthographicController myCam;
	std::shared_ptr<VIIL::Shader> myShader;
	std::shared_ptr<VIIL::VertexArray> vArray;
	std::shared_ptr<VIIL::Texture2D> ring;
	glm::vec3 objPos;

public:
	TestLayer() :
		Layer("TestLayer"), myCam(1080.0f / 540.0f, true), objPos({0.0f, 0.0f, 0.0f})
	{
		VL_APP_TRACE("Constructed TestLayer");
		float aspectRatio = VIIL::Renderer::get().getCurrentAspectRatio();

		unsigned int indices[6] = { 0, 1, 2, 2, 3, 0 };

		float vertices[5 * 4] =
		{
			-1.0f, -1.0f, 50.0f,  .0f,  .0f,
			 1.0f, -1.0f, 50.0f, 1.0f,  .0f,
			 1.0f,  1.0f, 50.0f, 1.0f, 1.0f,
			-1.0f,  1.0f, 50.0f,  .0f, 1.0f
		};

		ring = VIIL::Texture2D::create("resources/images/rings_3.png");
		myShader = VIIL::Shader::Create(VIIL::createFile("src/shaders/myTestShader/TestShaderProgram.glsl"));

		int slotToBind = 0;
		ring->bind(slotToBind);
		myShader->setUniformInt("image", slotToBind);

		vArray = VIIL::VertexArray::Create();
		auto vBuffer = VIIL::VertexBuffer::Create(vertices, sizeof(vertices));

		vBuffer->setLayout(
			{
				{ VIIL::ShaderDataType::FLOAT3, "myPosition"},
				{ VIIL::ShaderDataType::FLOAT2, "inTextureCoords"}
			});

		vArray->addVertexBuffer(vBuffer);
		vArray->setIndexBuffer(VIIL::IndexBuffer::Create(indices, sizeof(indices)));
	}

	~TestLayer()
	{
		VL_APP_TRACE("Destroyed test layer");
	}

	void onUpdate(float deltaTime) override
	{
		float objMovementAmount = deltaTime * 25;

		myCam.OnUpdate(deltaTime);

		modifyObjectLocationPerUserInput(objMovementAmount);

		VIIL::Scene myScene = VIIL::Scene(myCam);
		
		glm::mat4 objTransform = glm::translate(glm::mat4(1.0f), objPos);
		glm::mat4 objScale = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f));

		myScene.setObjectToScene(myShader, vArray, objTransform * objScale);

		VIIL::Renderer::get().drawScene(myScene);
	}

	void onEvent(VIIL::Event& e) override
	{
		myCam.OnEvent(e);
	}

	void modifyObjectLocationPerUserInput(float objMovementAmount)
	{
		VIIL::InputCache& input = VIIL::InputCache::get();

		if (input.isKeyPressed(VIIL::UP_ARROW))
		{
			objPos = { objPos.x, objPos.y + objMovementAmount, objPos.z };
		}
		else if (input.isKeyPressed(VIIL::DOWN_ARROW))
		{
			objPos = { objPos.x, objPos.y - objMovementAmount, objPos.z };
		}

		if (input.isKeyPressed(VIIL::RIGHT_ARROW))
		{
			objPos = { objPos.x + objMovementAmount, objPos.y, objPos.z };
		}
		else if (input.isKeyPressed(VIIL::LEFT_ARROW))
		{
			objPos = { objPos.x - objMovementAmount, objPos.y, objPos.z };
		}
	}

};