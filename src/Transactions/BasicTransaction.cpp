#include "BasicTransaction.hpp"
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
	stream >> userType;
	stream >> type;
	stream >> userCredits;

	return std::make_shared<BasicTransaction>(static_cast<TransactionType>(type), userName.c_str(), GetUserTypeFromString(userType), userCredits);
}

BasicTransaction::BasicTransaction(TransactionType type, const char *userName, UserType userType, float credits)
	: Transaction(type), userName{}, userType(userType), credits(credits)
{
	int len = strlen(userName);
	strncpy_s(this->userName, userName, std::min(len, USERNAME_LENGTH));
}