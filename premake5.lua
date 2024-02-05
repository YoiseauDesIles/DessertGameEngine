workspace "DessertGameEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to a root folder (Solution dir)
IncludeDir = {}
IncludeDir["GLFW"] = "DessertGameEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "DessertGameEngine/vendor/Glad/include"

include "DessertGameEngine/vendor/GLFW"
include "DessertGameEngine/vendor/Glad"

project "DessertGameEngine"
	location "DessertGameEngine"
	kind "SharedLib"
	language "C++"

	targetdir "bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/DessertGameEngine"
	objdir "bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/DessertGameEngine"

	pchheader "dgepch.h"
	pchsource "DessertGameEngine/src/dgepch.cpp"

	files
	{
		"DessertGameEngine/src/**.h",
		"DessertGameEngine/src/**.cpp"
	}

	includedirs
	{
		"$(SolutionDir)DessertGameEngine/src",
		"$(SolutionDir)DessertGameEngine/vendor/spdlog/include",
		"$(SolutionDir)%{IncludeDir.GLFW}",
		"$(SolutionDir)%{IncludeDir.Glad}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"DGE_PLATFORM_WINDOWS",
			"DGE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			"copy /B /Y ..\\bin\\%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}\\DessertGameEngine\\DessertGameEngine.dll ..\\bin\\%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}\\Sandbox\\ > nul"
		}

	filter "configurations:Debug"
		defines "DGE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "DGE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "DGE_DIST"
		buildoptions "/MD"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/Sandbox")
	objdir ("bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/Sandbox")

	files
	{
		"Sandbox/src/**.h",
		"Sandbox/src/**.cpp"
	}

	includedirs
	{
		"DessertGameEngine/vendor/spdlog/include",
		"DessertGameEngine/src"
	}

	links
	{
		"DessertGameEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

		defines
		{
			"DGE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DGE_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "DGE_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "DGE_DIST"
		buildoptions "/MD"
		optimize "On"