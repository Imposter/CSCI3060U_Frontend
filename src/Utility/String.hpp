#pragma once

#include <string>

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
	 * \brief Removes all whitespace from the left side of a string
	 * \param target String to trim
	 * \return Result string with no whitespaces on the left
	 */
	static std::string TrimLeft(std::string target);

	/**
	 * \brief Removes all whitespace from the right side of a string
	 * \param target String to trim
	 * \return Result string with no whitespaces on the right
	 */
	static std::string TrimRight(std::string target);

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

	/**
	 * \brief Checks if two strings are equal in their values
	 * \param str1 First string to compare
	 * \param str2 Second string to compare against
	 * \param caseInsensitive Should comparison be case insensitive
	 * \return Whether the strings are equal or not
	 */
	static bool Equals(std::string str1, std::string str2, bool caseInsensitive = false);
};