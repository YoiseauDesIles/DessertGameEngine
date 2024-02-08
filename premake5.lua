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
IncludeDir["ImGui"] = "DessertGameEngine/vendor/imgui"
IncludeDir["glm"] = "DessertGameEngine/vendor/glm"

include "DessertGameEngine/vendor/GLFW"
include "DessertGameEngine/vendor/Glad"
include "DessertGameEngine/vendor/imgui"


startproject = "Sandbox"

project "DessertGameEngine"
	location "DessertGameEngine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir "bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/DessertGameEngine"
	objdir "bin-int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/DessertGameEngine"

	pchheader "dgepch.h"
	pchsource "DessertGameEngine/src/dgepch.cpp"

	files
	{
		"DessertGameEngine/src/**.h",
		"DessertGameEngine/src/**.cpp",
		"DessertGameEngine/vendor/glm/glm/**.hpp",
		"DessertGameEngine/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"$(SolutionDir)DessertGameEngine/src",
		"$(SolutionDir)DessertGameEngine/vendor/spdlog/include",
		"$(SolutionDir)%{IncludeDir.GLFW}",
		"$(SolutionDir)%{IncludeDir.Glad}",
		"$(SolutionDir)%{IncludeDir.ImGui}",
		"$(SolutionDir)%{IncludeDir.glm}"

	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
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
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "DGE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "DGE_DIST"
		runtime "Release"
		optimize "On"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"DessertGameEngine/src",
		"DessertGameEngine/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"DessertGameEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"DGE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "DGE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "DGE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "DGE_DIST"
		runtime "Release"
		optimize "On"