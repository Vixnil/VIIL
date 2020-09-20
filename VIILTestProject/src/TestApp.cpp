#include <VIIL.h>

class TestApp : public VIIL::Application
{

public:

	TestApp():
		Application(VIIL::LV_TRACE, "TAPP", VIIL::Logger::defaultLogPattern, VIIL::LV_TRACE)
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