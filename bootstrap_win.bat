@echo off
set compiler=%1

if not %compiler%=vs (
	echo "NOTE: Must be run in Cygwin Environment"
)
echo "Preparing Frontend..."

if %compiler%=vs (
	echo "Generating Visual Studio project files..."
	"bin/premake5_windows.exe" --file=premake5.lua vs2017
) else (
	echo "Generating make files..."
	"bin/premake5_windows.exe" --file=premake5.lua gmake
)

echo "All done!"