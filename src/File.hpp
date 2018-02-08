#pragma once

#include <string>
#include <fstream>
#include <vector>

class File
{
	std::string name;
	std::fstream file;

public:
	explicit File(const std::string &name);
	~File();

	bool Open();
	void Close();

	std::vector<std::string> ReadLines();
	void WriteLine(std::string line);

	void Rewind();
};