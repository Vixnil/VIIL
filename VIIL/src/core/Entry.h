#pragma once

#include "standardUse.h"
#include "RuntimeObjs.h"
#include "InitializationServices.h"

#ifdef VIIL_PLATFORM_WINDOWS

extern std::unique_ptr<VIIL::Application> VIIL::createApplication();

int insanityCheck();

int main(int argc, char** argv)
{

 //  return insanityCheck();

    
	int returnCode = 0;
	{
		std::unique_ptr<VIIL::RuntimeObjs> engineData = std::make_unique<VIIL::RuntimeObjs>();
		{
			std::unique_ptr<VIIL::Application> application;

			try
			{
				application = VIIL::createApplication();

				InitializeEngine(engineData.get(), application.get());

				application->run();
			}
			catch (std::exception e)
			{
				returnCode = -1;
				VL_ENGINE_FATAL(e.what());
			}
		}
	}

	return returnCode;
    
}

int insanityCheck()
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

#endif