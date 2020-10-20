#include "standardUse.h"
#include "Application.h"

//temp includes
#include "core/renderer/OpenGL/OpenGLInclude.h"
#include "core/renderer/IndexBuffer.h"
#include "core/renderer/VertexBuffer.h"
#include "core/renderer/VertexArray.h"
#include "core/renderer/Shader.h"

namespace VIIL
{

#define bindEventHandler(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::applicationInstance = nullptr;

	Application::Application(VIIL::LEVEL engineLogLevel, const LogConfig& appLogData, VIIL::Window::WindowData windDef):
		appIsRunning(true), appLogConfig(appLogData.logName, appLogData.logPatrn, appLogData.logLevel), engineLogLevel(engineLogLevel)
	{
		VIIL::LogConfig engineConfig("VIIL", VIIL::Logger::defaultLogPattern, this->engineLogLevel);
		VIIL::Logger::init(engineConfig, this->appLogConfig);

		initialWindowDef = windDef;
		appWindow = createWindow(initialWindowDef);
		applicationInstance = this;

		VL_ENGINE_TRACE("Created application");
	}

	Application::~Application()
	{
		VL_ENGINE_TRACE("Destroyed application");
	}

	void Application::doStart()
	{
		if (!appWindow->isInitialized())
		{
			appIsRunning = false;
		}
		else
		{
			appWindow->setEventCallback(bindEventHandler(OnEvent));
		}
	}

	void Application::run()
	{
		VL_ENGINE_TRACE("Starting application");

		doStart();

		//below is temp code
		unsigned int indices[3] = { 0, 1, 2 };
		float vertices[3 * 3] =
		{
			-.5f, -.5f, .0f,
			 .5f, -.5f, .0f,
			 .0f,  .5f, .0f
		};

		std::string vertexSource = R"(
			#version 330 core

			layout(location = 0) in vec3 myPosition;	

			out vec3 outMyPosition;

			void main()
			{
				outMyPosition = (myPosition * .5) + .5;
				gl_Position = vec4(myPosition, 1.0);
			}
		)";

		std::string fragmentSource = R"(
			#version 330 core

			layout(location = 0) out vec4 colour;	

			in vec3 outMyPosition;

			void main()
			{
				colour = vec4(outMyPosition, 1.0);
			}
		)";

		auto myShader = Shader::Create(vertexSource, fragmentSource);
		auto vArray = VertexArray::Create(3, 3 * sizeof(float));
		auto vBuffer = VertexBuffer::Create(vertices, sizeof(vertices));
		auto iBuffer = IndexBuffer::Create(indices, sizeof(indices));

		myShader.get()->Bind();

		glVertexAttribPointer(0, iBuffer.get()->count(), GL_FLOAT, GL_FALSE, iBuffer.get()->count() * sizeof(float), nullptr);

		//not temp
		while (appIsRunning)
		{
			//temp
			glDrawElements(GL_TRIANGLES, iBuffer.get()->count(), GL_UNSIGNED_INT, nullptr);

			//not temp
			for (layerPtnr layer : layerStack)
			{
				layer->onUpdate();
			}

			MousePosition& pos = InputCache::get().getMousePosition();

			appWindow->update();
		}

		VL_ENGINE_TRACE("Application stopped, shutting down.");
	}

	void Application::OnEvent(Event& event)
	{
	//	VL_ENGINE_TRACE("Event occured: {0}", event.ToString());

		EventDispatcher dispatcher(event);
		dispatcher.dispatch<WindowClose>(bindEventHandler(windowCloseHandler));
		
		if (!event.isHandled())
		{
			for (LayerVector::iterator layerItr = layerStack.end(); layerItr != layerStack.begin();)
			{
				--layerItr;
				layerItr->get()->onEvent(event);

				if (event.isHandled())
				{
					break;
				}
			}
		}
	}

	bool Application::windowCloseHandler(WindowClose& event)
	{
		appIsRunning = false;

		event.setHandled(true);

		return true;
	}

	void Application::pushLayer(layerPtnr layer)
	{
		layerStack.addLayer(layer);
		layer->onAttached();
	}

	void Application::pushOverlay(layerPtnr overlay)
	{
		layerStack.addOverlay(overlay);
		overlay->onAttached();
	}

}