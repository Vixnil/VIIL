workspace "VIIL"
    architecture "x64"
    configurations{"Debug",
                   "Release"}

outDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "VIIL"
    location "VIIL"
    kind "SharedLib"
    language "C++"
    targetdir ("bin/" .. outDir .. "/%{prj.name}")
    objdir ("bin_inter/" .. outDir .. "/%{prj.name}")

    files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}

    includedirs{"%{prj.name}/lib/spdlog/include"}

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
        "VIIL/lib/spdlog/include",
        "VIIL/src"
    }

    links
    {
        "VIIL"
    }

    filter "configurations:Debug"
        defines {"VIIL_PLATFORM_WINDOWS"}
        symbols "On"

    filter "configurations:Release"
        defines {"VIIL_PLATFORM_WINDOWS", "VIIL_BUILD_RLS"}
        optimize "On"
