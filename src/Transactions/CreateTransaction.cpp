#include "CreateTransaction.hpp"
#include <sstream>
#include <exception>

// We only need CreateTransaction because that's the only one we're deserializing.
std::string CreateTransaction::Serializer::Serialize(CreateTransaction data)
{
	// Something along the lines of
	/*
	std::stringstream stream;
	stream << GetTransactionTypeString(data.GetType());
	stream << " ";
	stream << data.userName;
	stream << " ";
	stream << GetUserTypeString(data.userType);
	stream << " ";
	// ...
	*/
}

CreateTransaction CreateTransaction::Serializer::Deserialize(std::string serializedData)
{
	//throw std::exception("Not implemented");
}

CreateTransaction::CreateTransaction()
	: Transaction(kTransactionType_Create), userName{0}, userType(), credits(0)  {}