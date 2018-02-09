#pragma once

#include "UserType.hpp"
#include <string>

class User
{
    std::string name;
    UserType type;
    int credits;

public:
    User(std::string name, UserType type, int credits);

    const std::string &GetName() const;
    const UserType &GetType() const;
    const int &GetCredits() const;
    void SetCredits(int credits);
};