workspace 'group7'
	configurations { 'Debug', 'Release' }
	location 'build'
	
project 'frontend'
	kind 'ConsoleApp'
	language 'C++'
	cppdialect "C++14"
	toolset 'clang'
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