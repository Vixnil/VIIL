#include <VIIL.h>
#include <memory>


class TestLayer : public VIIL::Layer
{
public:
	TestLayer() :
		Layer("TestLayer")
	{
		VL_APP_TRACE("Constructed TestLayer");
	}

	void onUpdate() override
	{
		VL_APP_TRACE("TestLayer Updated");
	}

	void onEvent(VIIL::Event& event) override
	{
		VL_APP_TRACE("TestLayer event received: {0}", event.ToString());
	}

};

class TestApp : public VIIL::Application
{

public:

	TestApp(VIIL::Window::WindowData windDef):
		Application(VIIL::LEVEL::LV_TRACE, VIIL::LogConfig("TAPP", VIIL::Logger::defaultLogPattern, VIIL::LEVEL::LV_TRACE), windDef)
	{
		pushLayer(
			std::shared_ptr<TestLayer>(new TestLayer())
		);
	}

};

std::unique_ptr<VIIL::Application, VIIL::ApplicationDeleter> VIIL::createApplication()
{
	VIIL::Window::WindowData windDef;
	
	windDef.title = "MyTestApplication";
	windDef.height = 640;
	windDef.width = 480;

	return std::unique_ptr<TestApp, VIIL::ApplicationDeleter>(new TestApp(windDef));
}