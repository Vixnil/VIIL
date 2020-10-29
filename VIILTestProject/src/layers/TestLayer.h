#pragma once
#include <VIIL.h>
#include <glm/gtc/matrix_transform.hpp>

class TestLayer : public VIIL::Layer
{
	VIIL::CameraOrthographic myCam;
	std::shared_ptr<VIIL::Shader> myShader;
	std::shared_ptr<VIIL::VertexArray> vArray;
	std::shared_ptr<VIIL::Texture2D> ring;
	glm::vec3 trianglePos;

public:
	TestLayer() :
		Layer("TestLayer"), trianglePos(0.0f)
	{
		VL_APP_TRACE("Constructed TestLayer");
		float aspectRatio = VIIL::Renderer::get().getCurrentAspectRatio();
		myCam = VIIL::CameraOrthographic(
			{ -100.f, 100.5f, -100.0f, 100.f, -100.0f, 100.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, .45f, 1);

		unsigned int indices[6] = { 0, 1, 2, 2, 3, 0 };
		float vertices[5 * 4] =
		{
			-50.0f, -50.0f, .0f,  .0f,  .0f,
			 50.0f, -50.0f, .0f, 1.0f,  .0f,
			 50.0f,  50.0f, .0f, 1.0f, 1.0f,
			-50.0f,  50.0f, .0f,  .0f, 1.0f
		};

		std::string vertexSource = R"(
			#version 330 core

			layout(location = 0) in vec3 myPosition;	
			layout(location = 1) in vec2 inTextureCoords;

			uniform float aspectRatio;
			uniform mat4 vpMatrix;
			uniform mat4 objTransformMatrix;

			out vec2 textureCoords;

			void main()
			{
				textureCoords = inTextureCoords;
				gl_Position = ((vpMatrix * objTransformMatrix) * (vec4(aspectRatio, 1, 1, 1) * vec4(myPosition, 1)));
			}
		)";

		std::string fragmentSource = R"(
			#version 330 core

			layout(location = 0) out vec4 colour;	

			in vec2 textureCoords;
			uniform sampler2D image;

			void main()
			{
				
				colour = texture(image, textureCoords);
			}
		)";
		//colour = texture(image, textureCoords);
		//colour = vec4(textureCoords, 1, 1);
		ring = VIIL::Texture2D::create("resources/images/rings_3.png");
		myShader = VIIL::Shader::Create(vertexSource, fragmentSource);

		int slotToBind = 0;
		ring->bind(slotToBind);
		//myShader->setUniformFloat2("inTextureCoords", glm::vec2({ 1, 1 }));
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
		VIIL::InputCache& input = VIIL::InputCache::get();
		auto modLoc = myCam.getLocation();
		auto modRot = myCam.getRotation();

		float camMovementAmount = deltaTime * 1;
		float objMovementAmount = deltaTime * 25;

		if (input.isKeyPressed(VIIL::W))
		{
			modLoc = { modLoc.x, modLoc.y + camMovementAmount, modLoc.z };
		}
		else if (input.isKeyPressed(VIIL::S))
		{
			modLoc = { modLoc.x, modLoc.y - camMovementAmount, modLoc.z };
		}

		if (input.isKeyPressed(VIIL::A))
		{
			modLoc = { modLoc.x - camMovementAmount, modLoc.y, modLoc.z };
		}
		else if (input.isKeyPressed(VIIL::D))
		{
			modLoc = { modLoc.x + camMovementAmount, modLoc.y, modLoc.z };
		}


		if (input.isKeyPressed(VIIL::UP_ARROW))
		{
			trianglePos = { trianglePos.x, trianglePos.y + objMovementAmount, trianglePos.z };
		}
		else if (input.isKeyPressed(VIIL::DOWN_ARROW))
		{
			trianglePos = { trianglePos.x, trianglePos.y - objMovementAmount, trianglePos.z };
		}

		if (input.isKeyPressed(VIIL::RIGHT_ARROW))
		{
			trianglePos = { trianglePos.x + objMovementAmount, trianglePos.y, trianglePos.z };
		}
		else if (input.isKeyPressed(VIIL::LEFT_ARROW))
		{
			trianglePos = { trianglePos.x - objMovementAmount, trianglePos.y, trianglePos.z };
		}

		if (input.isKeyPressed(VIIL::E))
		{
			modRot = { modRot.x, modRot.y, modRot.z - camMovementAmount };
		}
		else if (input.isKeyPressed(VIIL::Q))
		{
			modRot = { modRot.x, modRot.y, modRot.z + camMovementAmount };
		}

		if (input.isKeyPressed(VIIL::R))
		{
			modRot = { modRot.x, modRot.y - camMovementAmount, modRot.z };
		}
		else if (input.isKeyPressed(VIIL::F))
		{
			modRot = { modRot.x, modRot.y + camMovementAmount, modRot.z };
		}

		if (input.isKeyPressed(VIIL::T))
		{
			modRot = { modRot.x- camMovementAmount, modRot.y , modRot.z };
		}
		else if (input.isKeyPressed(VIIL::G))
		{
			modRot = { modRot.x + camMovementAmount, modRot.y , modRot.z };
		}

		myCam.setLocation(modLoc);
		myCam.setRotation(modRot);
		myCam.setAspectRatio(VIIL::Renderer::get().getCurrentAspectRatio());

		VIIL::Scene myScene = VIIL::Scene(myCam);
		
		glm::mat4 triangleTransform = glm::translate(glm::mat4(1.0f), trianglePos);
		glm::mat4 triangleScale = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f));

		myScene.setObjectToScene(myShader, vArray, triangleTransform * triangleScale);

		//ring->bind(0);
		VIIL::Renderer::get().drawScene(myScene);
	}

	void onEvent(VIIL::Event& event) override
	{
		VIIL::EventDispatcher dispatcher(event);
	}

};