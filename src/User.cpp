#include "User.hpp"

User::User(std::string userName, UserType userType, int credits)
	: userName(userName), userType(userType), credits(credits) {}

const UserType &User::GetUserType() const
{
	return userType;
}

const int &User::GetCredits() const
{
	return credits;
}

void User::SetCredits(int credits)
{
	this->credits = credits;
}
