#include "LogoutHandler.hpp"

LogoutHandler::LogoutHandler(TransactionFile &transactionFile)
	: transactionFile(transactionFile) {}

TransactionType LogoutHandler::GetType()
{
	return kTransactionType_Logout;
}

std::string LogoutHandler::GetName()
{
	return "logout";
}

std::shared_ptr<Transaction> LogoutHandler::Handle(std::shared_ptr<User> &user)
{
	// TODO: Perform input/checks

	return NULL;
}

bool LogoutHandler::IsAllowed(std::shared_ptr<User> &user)
{
	// Logout is authorized for everyone
	return true;
}

bool LogoutHandler::IsAvailable(std::shared_ptr<User> &user)
{
	// Logout is only available if the user is logged in
	return user != NULL;
}