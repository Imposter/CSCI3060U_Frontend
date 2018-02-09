#pragma once

#include <string>

class String
{
public:
	static std::string PadLeft(std::string target, char character, int count);
	static std::string PadRight(std::string target, char character, int count);
};