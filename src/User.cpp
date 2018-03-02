#include "User.hpp"

User::User(std::string name, UserType type, double credits)
	: mName(name), mType(type), mCredits(credits), mCreditsAdded(0) {}

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
	mCredits = credits;
}

const double &User::GetAddedCredits() const
{
	return mCreditsAdded;
}

void User::AddCredits(double credits)
{
	mCreditsAdded += credits;
}
