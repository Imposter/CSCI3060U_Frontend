#include "UserFile.hpp"
#include <sstream>

UserFile::UserFile(std::string fileName)
    : File(fileName) {}

bool UserFile::Open()
{
    if (!File::Open())
        return false;

    // Read and parse users
	auto lines = ReadLines();
	for (auto line : lines)
	{
		std::stringstream stream(line); 
		
		std::string name;
		std::string type;
		float credits;

		stream >> name;
		stream >> type;
		stream >> credits;

		// End of file user
		if (name == "END")
			break;

		users.push_back(std::make_shared<User>(name, GetUserTypeFromString(type), credits));
	}

    return true;
}

std::shared_ptr<User> UserFile::GetUserByName(std::string userName)
{
    std::shared_ptr<User> result;

    // Find user by name
    for (auto user : users) 
    {
        if (user->GetName() == userName)
        {
            result = user;
            break;
        }
    }

    return result;
}