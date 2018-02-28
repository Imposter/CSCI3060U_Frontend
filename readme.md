# CSCI3060U Project

## Compiling

When using premake5 with gmake, specify a compiler of your choice (`gcc` or `clang`) with the option `--cc=COMPILER` or the system default will be used.

#### Building on Mac OSX
- Open a terminal in project root
- Run `bin/premake5_macosx --file=premake5.lua gmake` to generate the makefiles.
- Run `cd build` to go to the output directory
- Run `make all` to build the program `frontend`

#### Building on Linux
- Open a terminal in project root
- Run `bin/premake5_linux --file=premake5.lua gmake` to generate the makefiles.
- Run `cd build` to go to the output directory
- Run `make all` to build the program `frontend`

#### Building on Windows (Cygwin)
- Open a Cygwin terminal in project root
- Run `bin/premake5_windows.exe --file=premake5.lua gmake` to generate the makefiles.
- Run `cd build` to go to the output directory
- Run `make all` to build the program `frontend.exe`

#### Building on Windows (Visual Studio)
- Open a command prompt in project root
- Run `bin/premake5_windows.exe --file=premake5.lua vs2017` to generate the Visual Studio 2017 project files.
- Open `build/group7.sln` and build the solution.
  * Configurations:
    * debug_win32
    * release_win32
	
## Running Tests

#### Running tests on Mac OSX and Linux
- Open a terminal in project root
- Run `./run_tests.sh` to run all the tests

#### Running tests on Windows
- Open a command prompt in project root
- Run `./run_tests.bat` to run all the tests

## Authors
- Eyaz Rehman ([http://github.com/Imposter](GitHub))
- Spencer Bryson ([http://github.com/SpencerCBryson](GitHub))