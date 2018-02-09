#include "UserFile.hpp"

UserFile::UserFile(std::string fileName)
    : File(fileName) {}

bool UserFile::Open()
{
    if (!File::Open())
        return false;

    // TODO: Read and parse users
    

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