#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>

class Graphics
{
protected:
    bool isInit;
public:
    Graphics() :
        isInit(false)
    {}
    Graphics(bool condition) :
        isInit(condition)
    {}

    inline bool getIsInit() { return isInit; }
};

void glfw_error_callback(int error, const char* description)
{
    std::cout << ("GLFW: ", error, " - ", description) << std::endl;
}

class WindowsGraphics : public Graphics
{

public:
    WindowsGraphics() :
        Graphics(initialize())
    {
    }

    bool initialize()
    {
        glfwSetErrorCallback(glfw_error_callback);
        int value = glfwInit();
        return value;
    }

    ~WindowsGraphics()
    {
        glfwTerminate();
    }

};

int main()
{
    GLFWwindow* window;

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