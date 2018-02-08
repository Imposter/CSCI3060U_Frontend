#pragma once

#include <string>

class String
{
public:
	// TODO: Add padleft/right stuff, and int formatting for strings
	static std::string PadLeft(std::string target, char toPad);
	static std::string PadRight(std::string target, char toPad);
};