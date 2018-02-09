#pragma once

#include "File.hpp"
#include "User.hpp"
#include <vector>
#include <memory>

class UserFile : public File 
{
    std::vector<std::shared_ptr<User>> users;

public:
    UserFile(std::string fileName);
    bool Open();

	std::shared_ptr<User> GetUserByName(std::string userName);
};