#pragma once

#include "UserType.hpp"
#include <string>

class User
{
    std::string userName;
    UserType userType;
    int credits;
	// TODO: Add state (logged in, etc.)

public:
    User(std::string userName, UserType userType, int credits);

    const UserType &GetUserType() const;
    const int &GetCredits() const;
    void SetCredits(int credits);
};