#include "BasicTransaction.hpp"
#include "../Config.hpp"
#include "../Utility/String.hpp"
#include <algorithm>
#include <sstream>

std::string BasicTransaction::Serializer::Serialize(std::shared_ptr<BasicTransaction> data)
{
	std::stringstream stream;
	stream << GetTransactionTypeString(data->GetType()) << ' ';
	stream << String::PadRight(data->userName, ' ', USERNAME_LENGTH) << ' ';
	stream << GetUserTypeString(data->userType) << ' ';
	stream << String::PadLeft(String::Format("%.2f", data->credits), '0', CREDITS_LENGTH);

	return stream.str();
}

std::shared_ptr<BasicTransaction> BasicTransaction::Serializer::Deserialize(std::string serializedData)
{
	std::stringstream stream(serializedData);
	
	int type;
	std::string userName;
	std::string userType;
	double userCredits;

	stream >> type;
	stream.ignore();

	userName.resize(USERNAME_LENGTH);
	stream.read(const_cast<char *>(userName.c_str()), USERNAME_LENGTH);
	userName = String::TrimRight(userName);
	stream.ignore();
	
	stream >> userType;
	stream >> userCredits;

	return std::make_shared<BasicTransaction>(static_cast<TransactionType>(type), userName, GetUserTypeFromString(userType), userCredits);
}

BasicTransaction::BasicTransaction(TransactionType type, const std::string &userName, UserType userType, double credits)
	: Transaction(type), userName(userName), userType(userType), credits(credits) {}

const std::string &BasicTransaction::GetUserName() const
{
	return userName;
}

const UserType &BasicTransaction::GetUserType() const
{
	return userType;
}

const double &BasicTransaction::GetCredits() const
{
	return credits;
}