#include "String.hpp"

std::string String::PadLeft(std::string target, char character, int count)
{
	std::string output;
	
	output.append(count - target.size(), character);
	output.append(target);
	
	return output;
}

std::string String::PadRight(std::string target, char character, int count) 
{
	std::string output = target;
	
	output.append(count - target.size(), character);
	
	return output;
}