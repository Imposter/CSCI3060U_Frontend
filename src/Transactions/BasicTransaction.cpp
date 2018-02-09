#include "BasicTransaction.hpp"

std::string BasicTransaction::Serializer::Serialize(std::shared_ptr<BasicTransaction> data)
{
	// TODO: Implement
}

std::shared_ptr<BasicTransaction> BasicTransaction::Serializer::Deserialize(std::string serializedData)
{
	// TODO: Implement
}

BasicTransaction::BasicTransaction(TransactionType type)
	: Transaction(type), userName{0}, userType(), credits(0) {}