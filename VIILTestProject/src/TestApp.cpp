#include <VIIL.h>

class TestApp : public VIIL::Application
{

public:

	TestApp():
		Application(VIIL::LEVEL::LV_TRACE, "TAPP", VIIL::Logger::defaultLogPattern, VIIL::LEVEL::LV_TRACE)
	{

	}

	~TestApp()
	{

	}

};

VIIL::Application* VIIL::createApplication()
{
	return new TestApp();
}