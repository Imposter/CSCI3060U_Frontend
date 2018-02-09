#include "DeleteHandler.hpp"

DeleteHandler::DeleteHandler(TransactionFile &transactionFile, UserFile &userFile)
	: transactionFile(transactionFile), userFile(userFile) {}

TransactionType DeleteHandler::GetType()
{
	return kTransactionType_Delete;
}

std::string DeleteHandler::GetName()
{
	return "delete";
}

std::shared_ptr<Transaction> DeleteHandler::Handle(std::shared_ptr<User> &user)
{
    // TODO: Perform inputs/checks
    
    // NOTE: What if the user was created the same day? How to delete?

	return NULL;
}

bool DeleteHandler::IsAllowed(std::shared_ptr<User> &user)
{
	// TODO: Implement
}

bool DeleteHandler::IsAvailable(std::shared_ptr<User> &user)
{
	// TODO: Implement
}