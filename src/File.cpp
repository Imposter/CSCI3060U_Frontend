#include "File.hpp"
#include <string>

File::File(std::string name)
	: name(name) {}

File::~File()
{
	Close();
}

bool File::Open()
{
	file.open(name, std::ios::in | std::ios::out);
	return file.is_open();
}

void File::Close()
{
	if (file.is_open())
	{
		file.flush();
		file.close();
	}
}

std::vector<std::string> File::ReadLines()
{
	std::vector<std::string> result;
	if (!file.is_open())
		return result;

	while (!file.eof())
	{
		std::string line;
		getline(file, line);
		result.push_back(line);
	}

	return result;
}

void File::WriteLine(std::string line)
{
	file << line << std::endl;
}

void File::Rewind()
{
	if (file.is_open())
		file.seekg(std::ios::beg);
}

void File::Forward()
{
	if (file.is_open())
		file.seekg(std::ios::end);
}