#include "String.hpp"
#include <algorithm>

std::string String::PadLeft(std::string target, char character, int count)
{
	if (count - static_cast<int>(target.size()) <= 0)
		return target;

	std::string output;
	
	output.append(count - target.size(), character);
	output.append(target);
	
	return output;
}

std::string String::PadRight(std::string target, char character, int count) 
{
	if (count - static_cast<int>(target.size()) <= 0)
		return target;

	std::string output = target;
	
	output.append(count - target.size(), character);
	
	return output;
}

std::string String::Format(std::string format, ...)
{
	va_list arguments;
	va_start(arguments, format);

	auto length = vsnprintf(NULL, 0, format.c_str(), arguments) + 1;

	std::string result;
	result.resize(length);

	vsnprintf(const_cast<char *>(result.c_str()), length, format.c_str(), arguments);

	va_end(arguments);

	// Remove null terminator
	result.resize(length - 1);

	return result;
}

bool String::IsNumber(const std::string &string)
{
	return string.find_first_not_of("0123456789.") == std::string::npos && count(string.begin(), string.end(), '.') <= 1;
}