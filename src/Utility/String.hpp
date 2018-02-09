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
};