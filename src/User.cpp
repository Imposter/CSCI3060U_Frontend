#include "User.hpp"

User::User(std::string name, UserType type, double credits)
	: mName(name), mType(type), mCredits(credits) {}

const std::string &User::GetName() const
{
	return mName;
}

const UserType &User::GetType() const
{
	return mType;
}

const double &User::GetCredits() const
{
	return mCredits;
}

void User::SetCredits(double credits)
{
	this->mCredits = credits;
}
