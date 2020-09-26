workspace "VIIL"
    architecture "x64"
    configurations{"Debug",
                   "Release"}

outDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
glfwDir = "%{prj.name}/lib/platform/%{cfg.system}-%{cfg.architecture}/glfw-3.3.2"

project "MyGLFW"
    location "VIIL/lib/MyGLFW"
    kind "StaticLib"
    language "C"
    targetdir ("bin/" .. outDir .. "/%{prj.name}")
    objdir ("bin_inter/" .. outDir .. "/%{prj.name}")

    files
    {
        "%{prj.location}/include/GLFW/glfw3.h",
        "%{prj.location}/include/GLFW/glfw3native.h",
        "%{prj.location}/src/glfw_config.h",
        "%{prj.location}/src/context.c",
        "%{prj.location}/src/init.c",
        "%{prj.location}/src/input.c",
        "%{prj.location}/src/monitor.c",
        "%{prj.location}/src/vulkan.c",
        "%{prj.location}/src/window.c"
    }

    postbuildcommands
    {
   --     "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outDir .. "/VIILTestProject"
    }

    filter "system:windows"
        systemversion "latest"
        staticruntime "On"

        files
        {
            "%{prj.location}/src/win32_init.c",
            "%{prj.location}/src/win32_joystick.c",
            "%{prj.location}/src/win32_monitor.c",
            "%{prj.location}/src/win32_time.c",
            "%{prj.location}/src/win32_thread.c",
            "%{prj.location}/src/win32_window.c",
            "%{prj.location}/src/wgl_context.c",
            "%{prj.location}/src/egl_context.c",
            "%{prj.location}/src/osmesa_context.c"
        }

        defines 
        { 
            "_GLFW_WIN32",
            "_CRT_SECURE_NO_WARNINGS"
        }

project "VIIL"
    location "VIIL"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outDir .. "/%{prj.name}")
    objdir ("bin_inter/" .. outDir .. "/%{prj.name}")

    pchheader "standardUse.h"
    pchsource "VIIL/src/standardUse.cpp"

    files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}

    includedirs{ "%{prj.name}/src" 
                 ,"%{prj.name}/lib/spdlog/include"
                 ,"%{prj.name}/lib/MyGLFW/include"
                 }

    libdirs {"%{prj.name}/lib/**"}

    links
    {
        "MyGLFW",
        "opengl32"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
        systemversion "latest"

        defines {"VIIL_PLATFORM_WINDOWS", "VIIL_BUILD_DLL"}

        postbuildcommands
        {
            "{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outDir .. "/VIILTestProject"
        }

    filter "configurations:Debug"
        optimize "Off"
        symbols "On"

    filter "configurations:Release"
        defines {"VIIL_BUILD_RLS"}
        optimize "On"

project "VIILTestProject"
    location "VIILTestProject"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outDir .. "/%{prj.name}")
    objdir ("bin_inter/" .. outDir .. "/%{prj.name}")

    files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}

    includedirs
    {
        "VIIL/lib/**/include",
        "VIIL/src"
    }

    libdirs {"VIIL/lib/**"}

    links
    {
        "VIIL",
        "MyGLFW",
        "opengl32"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
        systemversion "latest"

    filter "configurations:Debug"
        defines {"VIIL_PLATFORM_WINDOWS"}
        symbols "On"

    filter "configurations:Release"
        defines {"VIIL_PLATFORM_WINDOWS", "VIIL_BUILD_RLS"}
        optimize "On"

project "GLFWTesting"
    location "GLFWTesting"
    kind "ConsoleApp"
    language "C++"
    targetdir ("bin/" .. outDir .. "/%{prj.name}")
    objdir ("bin_inter/" .. outDir .. "/%{prj.name}")

    files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}

    includedirs
    {
        "VIIL/lib/**/include",
        "VIIL/src"
    }

    libdirs {"VIIL/lib/**"}

    links
    {
        "VIIL",
        "MyGLFW",
        "opengl32"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
        systemversion "latest"

    filter "configurations:Debug"
        defines {"VIIL_PLATFORM_WINDOWS"}
        symbols "On"

    filter "configurations:Release"
        defines {"VIIL_PLATFORM_WINDOWS", "VIIL_BUILD_RLS"}
        optimize "On"
