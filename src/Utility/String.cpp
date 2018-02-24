#include "String.hpp"
#include <algorithm>
#include <cctype>

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
	
	target.append(count - target.size(), character);
	
	return target;
}

// Trimming implementation: https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
std::string String::TrimLeft(std::string target)
{
	target.erase(target.begin(), std::find_if(target.begin(), target.end(), [](char c)
	{
		return !isspace(c);
	}));

	return target;
}

// Trimming implementation: https://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
std::string String::TrimRight(std::string target)
{
	target.erase(std::find_if(target.rbegin(), target.rend(), [](int c) 
	{
		return !isspace(c);
	}).base(), target.end());

	return target;
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

bool String::Equals(std::string str1, std::string str2, bool caseInsensitive)
{
	if (str1.size() != str2.size())
		return false;

	auto size = str1.size() > str2.size() ? str2.size() : str1.size();
	for (size_t i = 0; i < size; i++)
		if (caseInsensitive && tolower(str1[i]) != tolower(str2[i]) || !caseInsensitive && str1[i] != str2[i])
			return false;

	return true;
}
