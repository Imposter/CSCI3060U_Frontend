#include "User.hpp"

User::User(std::string name, UserType type, int credits)
	: name(name), type(type), credits(credits) {}

const std::string &User::GetName() const
{
	return name;
}

const UserType &User::GetType() const
{
	return type;
}

const int &User::GetCredits() const
{
	return credits;
}

void User::SetCredits(int credits)
{
	this->credits = credits;
}
