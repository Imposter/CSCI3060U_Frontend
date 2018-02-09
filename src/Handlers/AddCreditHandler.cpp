#include "AddCreditHandler.hpp"

AddCreditHandler::AddCreditHandler(TransactionFile &transactionFile, UserFile &userFile, ItemFile &itemFile)
	: transactionFile(transactionFile), userFile(userFile), itemFile(itemFile) {}

TransactionType AddCreditHandler::GetType()
{
	return kTransactionType_AddCredit;
}

std::string AddCreditHandler::GetName()
{
	return "addcredit";
}

std::shared_ptr<Transaction> AddCreditHandler::Handle(std::shared_ptr<User> &user)
{
	// TODO: Perform input/checks

	return NULL;
}

bool AddCreditHandler::IsAllowed(std::shared_ptr<User> &user)
{
	// TODO: Implement
	return false;
}

bool AddCreditHandler::IsAvailable(std::shared_ptr<User> &user)
{
	// TODO: Implement
	return false;
}