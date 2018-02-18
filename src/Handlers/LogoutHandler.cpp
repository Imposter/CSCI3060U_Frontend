#include "LogoutHandler.hpp"
#include "../Transactions/LogoutTransaction.hpp"
#include <iostream>

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
	// Temporarily copy pointer to user
	std::shared_ptr<User> tempUser = user;

	// Set as not logged in
	user = NULL;

	// Print session end message
	std::cout << "Session terminated" << std::endl;
	std::cout << "Goodbye " << tempUser->GetName() << std::endl;

	return std::make_shared<LogoutTransaction>(tempUser->GetName(), tempUser->GetType(), tempUser->GetCredits());
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