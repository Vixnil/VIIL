#include <VIIL.h>
#include <memory>

class TestApp : public VIIL::Application
{

public:

	TestApp(VIIL::Window::WindowData windDef):
		Application(VIIL::LEVEL::LV_TRACE, VIIL::LogConfig("TAPP", VIIL::Logger::defaultLogPattern, VIIL::LEVEL::LV_TRACE), windDef)
	{}

	~TestApp()
	{

	}

};

std::unique_ptr<VIIL::Application> VIIL::createApplication()
{
	VIIL::Window::WindowData windDef;
	
	windDef.title = "MyTestApplication";
	windDef.height = 640;
	windDef.width = 480;

	return std::make_unique<TestApp>(windDef);
}