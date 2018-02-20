#pragma once

#include <string>
#include <stdarg.h>

/**
 * \brief String utility for STL string manipulation
 */
class String
{
public:
	/**
	 * \brief Adds padding to the left of the target string with the specified character and count
	 * \param target String to add padding to
	 * \param character Padding character to add
	 * \param count Amount of padding to add
	 * \return Copy of the target string with padding added to the left
	 */
	static std::string PadLeft(std::string target, char character, int count);

	/**
	 * \brief Adds padding to the right of the target string with the specified character and count
	 * \param target String to add padding to
	 * \param character Padding character to add
	 * \param count Amount of padding to add
	 * \return Copy of the target string with padding added to the right
	 */
	static std::string PadRight(std::string target, char character, int count);

	/**
	 * \brief Formats a string using a C format and argument style
	 * \param format C string format
	 * \param ... Variable format arguments
	 * \return Formatted string
	 */
	static std::string Format(std::string format, ...);

	/**
	 * \brief Checks if a string is a number or not, cannot include commas. Decimals are allowed
	 * \param string Number string
	 * \return Whether the string is a number or not
	 */
	static bool IsNumber(const std::string &string);
};