#include "User.hpp"

User::User(std::string name, UserType type, float credits)
	: name(name), type(type), credits(credits) {}

const std::string &User::GetName() const
{
	return name;
}

const UserType &User::GetType() const
{
	return type;
}

const float &User::GetCredits() const
{
	return credits;
}

void User::SetCredits(float credits)
{
	this->credits = credits;
}
