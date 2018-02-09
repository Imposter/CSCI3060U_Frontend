#include "CreateHandler.hpp"

CreateHandler::CreateHandler(TransactionFile &transactionFile, UserFile &userFile)
	: transactionFile(transactionFile), userFile(userFile) {}

TransactionType CreateHandler::GetType()
{
	return kTransactionType_Create;
}

std::string CreateHandler::GetName()
{
	return "create";
}

std::shared_ptr<Transaction> CreateHandler::Handle(std::shared_ptr<User> &user)
{
	// TODO: Perform inputs/checks

	return NULL;
}

bool CreateHandler::IsAllowed(std::shared_ptr<User> &user)
{
	// TODO: Implement
}

bool CreateHandler::IsAvailable(std::shared_ptr<User> &user)
{
	// TODO: Implement
}