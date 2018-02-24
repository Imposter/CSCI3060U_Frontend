#include "UserFile.hpp"
#include "Utility/String.hpp"
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
		double credits;

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

std::vector<std::shared_ptr<User>> &UserFile::GetUsers()
{
	return users;
}

std::shared_ptr<User> UserFile::GetUserByName(std::string userName)
{
    std::shared_ptr<User> result;

    // Find user by name
    for (auto user : users) 
    {
		// Perform a case insensitive comparison to guarantee uniqueness
        if (String::Equals(user->GetName(), userName, true))
        {
            result = user;
            break;
        }
    }

    return result;
}