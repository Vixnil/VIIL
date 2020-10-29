#include <VIIL.h>
#include "layers/BackgroundLayer.h"
#include "layers/TestLayer.h"

class TestApp : public VIIL::Application
{
public:

	TestApp(VIIL::Window::WindowData windDef):
		Application(VIIL::LEVEL::LV_TRACE, VIIL::LogConfig("TAPP", VIIL::Logger::defaultLogPattern, VIIL::LEVEL::LV_TRACE), windDef)
	{
		pushLayer(std::shared_ptr<BackgroundLayer>(new BackgroundLayer()));
		pushOverlay(std::shared_ptr<TestLayer>(new TestLayer()));
	}

};

std::unique_ptr<VIIL::Application, VIIL::ApplicationDeleter> VIIL::createApplication()
{
	VIIL::Window::WindowData windDef;
	
	windDef.title = "MyTestApplication";
	windDef.height = 540;
	windDef.width = 1080;

	return std::unique_ptr<TestApp, VIIL::ApplicationDeleter>(new TestApp(windDef));
}