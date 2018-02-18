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
	stream << String::PadLeft(String::Format("%.2f", data->credits), '0', 6);

	return stream.str();
}

std::shared_ptr<BasicTransaction> BasicTransaction::Serializer::Deserialize(std::string serializedData)
{
	std::stringstream stream(serializedData);
	
	int type;
	std::string userName;
	std::string userType;
	float userCredits;

	stream >> type;
	stream >> userName;
	stream >> userType;
	stream >> userCredits;

	return std::make_shared<BasicTransaction>(static_cast<TransactionType>(type), userName, GetUserTypeFromString(userType), userCredits);
}

BasicTransaction::BasicTransaction(TransactionType type, const std::string &userName, UserType userType, float credits)
	: Transaction(type), userName(userName), userType(userType), credits(credits) {}

const std::string &BasicTransaction::GetUserName() const
{
	return userName;
}

const UserType &BasicTransaction::GetUserType() const
{
	return userType;
}

const float &BasicTransaction::GetCredits() const
{
	return credits;
}