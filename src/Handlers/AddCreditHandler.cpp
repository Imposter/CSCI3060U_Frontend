#include "AddCreditHandler.hpp"

AddCreditHandler::AddCreditHandler(TransactionFile &transactionFile, UserFile &userFile, ItemFile &itemFile)
	: mTransactionFile(transactionFile), mUserFile(userFile), mItemFile(itemFile) {}

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

bool AddCreditHandler::IsAvailable(std::shared_ptr<User> &user)
{
	// TODO: Implement
	return false;
}