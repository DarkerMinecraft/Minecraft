workspace "Minecraft"
	architecture "x64"
	startproject "Minecraft"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "vendor/GLFW/include"
IncludeDir["Glad"] = "vendor/Glad/include"
IncludeDir["glm"] = "vendor/glm"

group "Dependencies"
	include "vendor/GLFW"
	include "vendor/Glad"
group ""

project "Minecraft"
	location "Minecraft"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/Core/**.h",
		"%{prj.name}/Core/**.cpp",
		"%{prj.name}/Core/**.glsl"
	}

	includedirs 
	{
		"%{IncludeDir.glm}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.GLFW}", 
		"%{prj.name}/Core"
	}

	links 
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}

	defines 
	{
		"GLFW_INCLUDE_NONE"
	}

	filter "system:windows"
		systemversion "latest"

		filter "configurations:Debug"
			defines "EN_DEBUG"
			runtime "Debug"
			symbols "on"
			
		filter "configurations:Release"
			defines "EN_RELEASE"
			runtime "Release"
			optimize "on"

		filter "configurations:Dist"
			defines "EN_DIST"
			runtime "Release"
			optimize "on"