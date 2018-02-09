#pragma once

#include <string>

enum UserType
{
    kUserType_Buy,
    kUserType_Sell,
    kUserType_Full,
    kUserType_Admin
};

std::string GetUserTypeString(UserType type);