#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>

int bugReproduction();
int insanityCheck();

int main()
{
    return insanityCheck();
}

#include <GLFW/glfw3.h>

class Graphics
{
protected:
    bool isInit;
public:

    virtual void prepareDelete() {};
    inline bool getIsInit() { return isInit; }
};

struct GraphicsDeleter
{
    void operator()(Graphics* gphs) const
    {
        gphs->prepareDelete();
        delete gphs;
    }
};

#include <GLFW/glfw3.h>

class WindowsGraphics : public Graphics
{

public:
    WindowsGraphics()
    {
    }

    void initialize()
    {
        isInit = glfwInit();
    }

    static std::unique_ptr<Graphics, GraphicsDeleter> initializeGraphics()
    {
        std::unique_ptr<WindowsGraphics, GraphicsDeleter> gphs = std::unique_ptr<WindowsGraphics, GraphicsDeleter>(new WindowsGraphics());

        gphs->initialize();
        return gphs;
    }

    void prepareDelete()
    {
        glfwTerminate();
    }
};

struct RuntimeObjs
{
    std::unique_ptr<Graphics, GraphicsDeleter> g;

    RuntimeObjs(){}
};

#include <GLFW/glfw3.h>

class Window
{
public:
    struct WindowData
    {
        std::string title;
        int width, height;
        bool isFullScreen;

    };

protected:
    WindowData wData;
    bool initialized;

public:

    virtual void update() = 0;
    virtual inline unsigned int getWdith() { return wData.width; }
    virtual inline unsigned int getHeight() { return wData.height; }

    bool isInitialized()
    {
        return initialized;
    }

};

class WindowsWdw : public Window
{
    GLFWwindow* windowHndl;
public:
    WindowsWdw(const WindowData& winData)
    {
        initializeWindow(winData);
    }

    virtual ~WindowsWdw()
    {
        glfwDestroyWindow(windowHndl);
    }

    void initializeWindow(const WindowData& winData)
    {
        wData.height = winData.height;
        wData.width = winData.width;
        wData.title = winData.title;
        wData.isFullScreen = winData.isFullScreen;

        windowHndl = glfwCreateWindow(wData.width, wData.height, wData.title.c_str(), NULL, NULL);

        if (!windowHndl)
        {
            initialized = false;
            return;
        }

        //glfwSetWindowCloseCallback(windowHndl, glfw_window_close_callback);

        glfwMakeContextCurrent(windowHndl);
        //	glfwSetWindowUserPointer(windowHndl, &wData);
        //	glfwSwapInterval(1);
        initialized = true;
    }

    void WindowsWdw::update()
    {
        glfwPollEvents();
        glfwSwapBuffers(windowHndl);
    }
};

std::unique_ptr<Window> createWindow(const Window::WindowData& winData)
{
    return std::make_unique<WindowsWdw>(winData);
}

#include <GLFW/glfw3.h>

class Application
{
    //Class variable used to stop application running in the run method
    bool appIsRunning;
    std::unique_ptr<Window> appWindow;
    Window::WindowData initialWindowDef;

public:
    Application(Window::WindowData windDef) :
        appIsRunning(true)
    {
        initialWindowDef = windDef;
    }

    virtual ~Application()
    {

    }

    virtual void run()
    {
        doStart();

        while (appIsRunning)
        {
            appWindow->update();
        }
    }

    virtual void doStart() 
    {
        appWindow = createWindow(initialWindowDef);

        if (!appWindow->isInitialized())
        {
            appIsRunning = false;
        }
    }

    virtual void prepareDelete() {}

};

struct ApplicationDeleter
{
    void operator()(Application* app) const
    {
        app->prepareDelete();
        delete app;
    }
};

#include <GLFW/glfw3.h>

void InitializeEngine(RuntimeObjs* engineData, const Application* app)
{
    engineData->g = WindowsGraphics::initializeGraphics();

    if (!engineData->g->getIsInit())
    {
        throw std::exception("Failed to initialize graphics libraries.");
    }
}

#include <GLFW/glfw3.h>

class TestApp : public Application
{

public:

    TestApp(Window::WindowData windDef) :
        Application(windDef)
    {}

};

std::unique_ptr<Application, ApplicationDeleter> createApplication()
{
    Window::WindowData windDef;

    windDef.title = "MyTestApplication";
    windDef.height = 640;
    windDef.width = 480;

    return std::unique_ptr<TestApp, ApplicationDeleter>(new TestApp(windDef));
}

#include <GLFW/glfw3.h>

int bugReproduction()
{
    int returnCode = 0;
    {
        std::unique_ptr<RuntimeObjs> engineData = std::make_unique<RuntimeObjs>();

        try
        {
            std::unique_ptr<Application, ApplicationDeleter> application = createApplication();

            InitializeEngine(engineData.get(), application.get());

            application->run();
        }
        catch (std::exception e)
        {
            returnCode = -1;
        }
    }

    return returnCode;
}

int insanityCheck()
{
    GLFWwindow* window;

    int didInit = glfwInit();

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
}