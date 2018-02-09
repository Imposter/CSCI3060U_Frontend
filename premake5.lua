workspace 'group7'
	configurations { 'Debug', 'Release' }
	location 'build'
	
project 'frontend'
	kind 'ConsoleApp'
	language 'C++'
	cppdialect "C++14"
	toolset 'clang' -- NOTE: This will not work with Visual Studio (TODO: Use command line args to determine which toolset to use -- premake docs)
	targetdir 'build/%{cfg.buildCfg}'
	
	files {
		'src/**.hpp',
		'src/**.cpp'
	}
	
	filter 'configurations:Debug'
		defines { 'DEBUG' }
		symbols 'On'

	filter 'configurations:Release'
		defines { 'NDEBUG' }
		optimize 'On'