#include "LoginHandler.hpp"
#include "../Config.hpp"
#include "../Transactions/LoginTransaction.hpp"
#include <iostream>

LoginHandler::LoginHandler(UserFile &userFile)
	: userFile(userFile) {}

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
	// Check if already logged in
	if (user)
	{
		std::cerr << "ERROR: Already logged in" << std::endl;
		return NULL;
	}

	// Get username
	std::string username;
	std::cout << "Enter your username: ";
	getline(std::cin, username);

	// Check username length
	if (username.size() > USERNAME_LENGTH)
	{
		std::cerr << "ERROR: Invalid username (too long)" << std::endl;
		return NULL;
	}

	// Check if account exists
	auto userAccount = userFile.GetUserByName(username);
	if (!userAccount)
	{
		std::cerr << "ERROR: Invalid username (does not exist)" << std::endl;
		return NULL;
	}

	// Welcome user differently if they are privileged
	if (userAccount->GetType() == kUserType_Admin)
		std::cout << "Privileged login accepted" << std::endl;
	else
		std::cout << "Login accepted" << std::endl;

	// Set user logged in
	user = userAccount;

	// Return a successful transaction
	return std::make_shared<LoginTransaction>(user->GetName().c_str(), user->GetType(), user->GetCredits());
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