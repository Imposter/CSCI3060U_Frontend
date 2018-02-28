#pragma once

#include <fstream>
#include <vector>

/**
 * \brief Basic file class providing input and output in terms of lines
 */
class File
{
protected:
	std::string mName;
	std::fstream mFile;

public:
	/**
	 * \brief Initializes file with file path
	 * \param name File path
	 */
	explicit File(std::string name);
	
	/**
	 * \brief Closes file if still open
	 */
	~File();

	/**
	 * \brief Opens a handle to the file
	 * \param append Open file in append mode
	 * \return Whether the file was successfully opened or not
	 */
	bool Open(bool append = false);

	/**
	 * \brief Closes file handle
	 */
	void Close();

	/**
	 * \brief Reads all the lines in the file
	 * \return All the lines read from the file
	 */
	std::vector<std::string> ReadLines();

	/**
	 * \brief Appends line to the end of the file
	 * \param line Line to append to file
	 */
	void WriteLine(std::string line);

	/**
	 * \brief Resets the position to the start of the file
	 */
	void Rewind();

	/**
	 * \brief Sets the position to the end of the file
	 */
	void Forward();
};