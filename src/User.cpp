#include "User.hpp"

User::User(std::string name, UserType type, double credits)
	: name(name), type(type), credits(credits) {}

const std::string &User::GetName() const
{
	return name;
}

const UserType &User::GetType() const
{
	return type;
}

const double &User::GetCredits() const
{
	return credits;
}

void User::SetCredits(double credits)
{
	this->credits = credits;
}
