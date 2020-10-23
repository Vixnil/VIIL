#pragma once
#include <VIIL.h>

class TestLayer : public VIIL::Layer
{
	std::unique_ptr<VIIL::Shader> myShader;
	std::shared_ptr<VIIL::VertexArray> vArray;

public:
	TestLayer() :
		Layer("TestLayer")
	{
		VL_APP_TRACE("Constructed TestLayer");
		unsigned int indices[6] = { 0, 1, 2,
									2, 3, 0 };
		float vertices[4 * 7] =
		{
			-.5f, -.5f, .0f,     .5f, .0f, 1.0f, 1.0f,
			 .5f, -.5f, .0f,     0.0f, .0f, 1.0f, .4f,
			 .5f,  .5f, .0f,     1.0f, .0f, 1.0f, .6f,
			 -.5f,  .5f, .0f,     .5f, .0f, 1.0f, 1.0f
		};

		std::string vertexSource = R"(
			#version 330 core

			layout(location = 0) in vec3 myPosition;	
			layout(location = 1) in vec4 myColour;

			out vec3 outMyPosition;
			out vec4 myOutColour;

			void main()
			{
				myOutColour = myColour;
				outMyPosition = (myPosition * .5) + .5;
				gl_Position = vec4(myPosition, 1.0);
			}
		)";

		std::string fragmentSource = R"(
			#version 330 core

			layout(location = 0) out vec4 colour;	

			in vec3 outMyPosition;
			in vec4 myOutColour;

			void main()
			{
				colour = myOutColour;
			}
		)";

		myShader = VIIL::Shader::Create(vertexSource, fragmentSource);
		vArray = VIIL::VertexArray::Create();
		auto vBuffer = VIIL::VertexBuffer::Create(vertices, sizeof(vertices));

		vBuffer->setLayout(
			{
				{ VIIL::ShaderDataType::FLOAT3, "myPosition"},
				{ VIIL::ShaderDataType::FLOAT4, "myColour"},
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
		myShader->Bind();
		VIIL::Renderer::submit(vArray);
	}

	void onEvent(VIIL::Event& event) override
	{
	}

};