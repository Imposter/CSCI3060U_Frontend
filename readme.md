# CSCI3060U Project

## Installation

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
- Open a Cygwin terminal in project root
- Run `bin/premake5_windows.exe --file=premake5.lua vs2017` to generate the Visual Studio 2017 project files.
- Open `build/group7.sln` and build the solution.
  * Configurations:
    * debug_win32
    * release_win32

## Authors
Eyaz Rehman ([http://github.com/Imposter](GitHub))
Spencer Bryson ([http://github.com/SpencerCBryson](GitHub))