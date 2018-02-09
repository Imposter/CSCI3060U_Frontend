#include "RefundHandler.hpp"

RefundHandler::RefundHandler(TransactionFile &transactionFile, UserFile &userFile)
	: transactionFile(transactionFile), userFile(userFile) {}

TransactionType RefundHandler::GetType()
{
	return kTransactionType_Refund;
}

std::string RefundHandler::GetName()
{
	return "refund";
}

std::shared_ptr<Transaction> RefundHandler::Handle(std::shared_ptr<User> &user)
{
	// TODO: Perform input/checks

	return NULL;
}

bool RefundHandler::IsAllowed(std::shared_ptr<User> &user)
{
	// TODO: Implement
	return false;
}

bool RefundHandler::IsAvailable(std::shared_ptr<User> &user)
{
	// TODO: Implement
	return false;
}