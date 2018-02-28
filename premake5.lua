workspace 'group7'
	configurations { 'Debug', 'Release' }
	location 'build'
	
project 'frontend'
	kind 'ConsoleApp'
	language 'C++'
	cppdialect 'C++14'
	targetdir 'build/%{cfg.buildCfg}'
	
	files {
		'src/**.hpp',
		'src/**.cpp'
	}

	filter 'platforms:Win32'
		system 'Windows'
		architecture 'x32'
		defines { '_CRT_SECURE_NO_WARNINGS' }
	
	filter 'configurations:Debug'
		defines { 'DEBUG' }
		symbols 'On'

	filter 'configurations:Release'
		defines { 'NDEBUG' }
		optimize 'On'