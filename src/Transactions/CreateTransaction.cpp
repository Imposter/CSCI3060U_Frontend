#include "CreateTransaction.hpp"

std::string CreateTransaction::Serializer::Serialize(std::shared_ptr<CreateTransaction> data)
{
	// TODO: Implement
}

std::shared_ptr<CreateTransaction> CreateTransaction::Serializer::Deserialize(std::string serializedData)
{
	// TODO: Implement
}

CreateTransaction::CreateTransaction()
	: Transaction(kTransactionType_Create), userName{0}, userType(), credits(0)  {}