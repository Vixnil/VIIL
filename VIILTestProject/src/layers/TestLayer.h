#pragma once
#include <VIIL.h>
#include <chrono>
#include <ctime>

class TestLayer : public VIIL::Layer
{
	VIIL::Camera2D myCam;
	std::shared_ptr<VIIL::Shader> myShader;
	std::shared_ptr<VIIL::VertexArray> vArray;
	std::chrono::steady_clock::duration timerStart;
	int numFramesSinceStart = -1;
	int numFramesLastSecond = 0;

public:
	TestLayer() :
		Layer("TestLayer")
	{
		VL_APP_TRACE("Constructed TestLayer");

		myCam = VIIL::Camera2D({ -1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f }, { 0.0f, 0.0f, 0.0f }, { 0.0f, 0.0f, 0.0f }, 1, .45f);

		unsigned int indices[3] = { 0, 1, 2};//	2, 3, 0 };
		float vertices[3 * 3] =
		{
			-.5f, -.5f, .0f, 
			 .5f, -.5f, .0f, 
			 .0f,  .5f, .0f 
		};

		std::string vertexSource = R"(
			#version 330 core

			layout(location = 0) in vec3 myPosition;	

			uniform mat4 vpMatrix;

			void main()
			{
				gl_Position = (vpMatrix * vec4(myPosition, 1));
			}
		)";

		std::string fragmentSource = R"(
			#version 330 core

			layout(location = 0) out vec4 colour;	

			void main()
			{
				colour = vec4(.8, .3, .6, 1);
			}
		)";

		myShader = VIIL::Shader::Create(vertexSource, fragmentSource);
		vArray = VIIL::VertexArray::Create();
		auto vBuffer = VIIL::VertexBuffer::Create(vertices, sizeof(vertices));

		vBuffer->setLayout(
			{
				{ VIIL::ShaderDataType::FLOAT3, "myPosition"},
			});

		vArray->addVertexBuffer(vBuffer);
		vArray->setIndexBuffer(VIIL::IndexBuffer::Create(indices, sizeof(indices)));
	}

	~TestLayer()
	{
		VL_APP_TRACE("Destroyed test layer");
	}

	void onUpdate() override
	{
		VIIL::InputCache& input = VIIL::InputCache::get();
		auto currLoc = myCam.getLocation();

		auto timerEnd = std::chrono::high_resolution_clock::now().time_since_epoch();
		double miliSeconds = (((timerEnd - timerStart)) / CLOCKS_PER_SEC).count()/1000;

		if (miliSeconds > 1000)
		{
			numFramesLastSecond = numFramesSinceStart;
			timerStart = std::chrono::high_resolution_clock::now().time_since_epoch();
			numFramesSinceStart = 0;
		}

		if (input.isKeyPressed(VIIL::W))
		{
			myCam.setLocation({ currLoc.x, currLoc.y - .01, currLoc.z });
		}
		else if (input.isKeyPressed(VIIL::S))
		{
			myCam.setLocation({ currLoc.x, currLoc.y + .01, currLoc.z });
		}
		else if (input.isKeyPressed(VIIL::A))
		{
			myCam.setLocation({ currLoc.x + .01, currLoc.y, currLoc.z });
		}
		else if (input.isKeyPressed(VIIL::D))
		{
			myCam.setLocation({ currLoc.x - .01, currLoc.y, currLoc.z });
		}

		if (input.isKeyPressed(VIIL::F1))
		{
			VL_APP_TRACE("Number of updates ran last second: {0}", numFramesLastSecond);
		}

		VIIL::Scene myScene = VIIL::Scene(myCam);

		myScene.setObjectToScene(myShader, vArray);

		VIIL::Renderer::drawScene(myScene);
		numFramesSinceStart++;
	}

	void onEvent(VIIL::Event& event) override
	{

	}

};