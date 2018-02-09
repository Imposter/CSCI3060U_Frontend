#include "LoginHandler.hpp"
#include <iostream>

LoginHandler::LoginHandler(TransactionFile &transactionFile, UserFile &userFile)
	: transactionFile(transactionFile), userFile(userFile) {}

TransactionType LoginHandler::GetType()
{
	return kTransactionType_Login;
}

std::string LoginHandler::GetName()
{
	return "login";
}

std::shared_ptr<Transaction> LoginHandler::Handle(std::shared_ptr<User> &user)
{
	std::string input;
	std::cout << "Enter your username: ";
	std::cin >> input;
	
	// TODO: Check if account exists, etc.
	// TODO: Check length

	// On successful login, set user to std::make_shared<User>(constructor args here)
	// and return successful transaction

	return NULL;
}

bool LoginHandler::IsAllowed(std::shared_ptr<User> &user)
{
	// Login is authorized for everyone
	return true;
}

bool LoginHandler::IsAvailable(std::shared_ptr<User> &user)
{
	// Login is only available if the user hasn't logged in
	return user == NULL;
}