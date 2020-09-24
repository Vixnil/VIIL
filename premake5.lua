workspace "VIIL"
    architecture "x64"
    configurations{"Debug",
                   "Release"}

outDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
glfwDir = "%{prj.name}/lib/platform/%{cfg.system}-%{cfg.architecture}/glfw-3.3.2"

project "VIIL"
    location "VIIL"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outDir .. "/%{prj.name}")
    objdir ("bin_inter/" .. outDir .. "/%{prj.name}")

    pchheader "standardUse.h"
    pchsource "VIIL/src/standardUse.cpp"

    files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}

    includedirs{ "%{prj.name}/src", 
                 "%{prj.name}/lib/spdlog/include",
                 (glfwDir .. "/include")}

    libdirs {"%{prj.name}/lib/**"}

    links
    {
        "glfw3",
        "opengl32"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "Off"
        systemversion "latest"

        defines {"VIIL_PLATFORM_WINDOWS", "VIIL_BUILD_DLL"}

        postbuildcommands
        {
            "{COPY} " .. glfwDir .. "/lib-vc2019" .. " ../bin/" .. outDir .. "/VIILTestProject",
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
        "glfw3",
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
