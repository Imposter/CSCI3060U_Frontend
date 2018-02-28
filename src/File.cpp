#include "File.hpp"
#include <string>

File::File(std::string name)
	: mName(name) {}

File::~File()
{
	Close();
}

bool File::Open(bool append)
{
	auto openMode = std::fstream::in | std::fstream::out;
	if (append) openMode |= std::fstream::app;

	mFile.open(mName, openMode);
	return mFile.is_open();
}

void File::Close()
{
	if (mFile.is_open())
	{
		mFile.flush();
		mFile.close();
	}
}

std::vector<std::string> File::ReadLines()
{
	std::vector<std::string> result;
	if (!mFile.is_open())
		return result;

	while (!mFile.eof())
	{
		std::string line;
		getline(mFile, line);
		result.push_back(line);
	}

	return result;
}

void File::WriteLine(std::string line)
{
	mFile << line << std::endl;
}

void File::Rewind()
{
	if (mFile.is_open())
	{
		mFile.clear();
		mFile.seekg(0, std::ios::beg);
	}
}

void File::Forward()
{
	if (mFile.is_open())
	{
		mFile.clear();
		mFile.seekg(0, std::ios::end);
	}
}