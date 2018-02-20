#include "CreateHandler.hpp"
#include "../Transactions/CreateTransaction.hpp"
#include "../Config.hpp"
#include "../Utility/String.hpp"
#include <iostream>

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
	// Get username
	std::string userName;
	std::cout << "Enter username: ";
	getline(std::cin, userName);

	// Check username length
	if (userName.size() > USERNAME_LENGTH)
	{
		std::cerr << "ERROR: Invalid username (too long)" << std::endl;
		return NULL;
	}

	// Check if account exists in the user file
	auto userAccount = userFile.GetUserByName(userName);
	if (userAccount)
	{
		std::cerr << "ERROR: Invalid username (in use)" << std::endl;
		return NULL;
	}

	// Check if the transaction to create a user is already pending
	for (auto t : transactionFile.GetTransactions(kTransactionType_Create))
	{
		auto transaction = PointerCast::Reinterpret<BasicTransaction>(t);
		if (transaction->GetUserName() == userName)
		{
			std::cerr << "ERROR: Invalid username (in use)" << std::endl;
			return NULL;
		}
	}

	// Get user type
	std::string userType;
	std::cout << "Enter user type: ";
	getline(std::cin, userType);

	// Convert to internal user type
	auto type = GetUserTypeFromLongString(userType);
	if (type == kUserType_None)
	{
		std::cerr << "ERROR: Invalid user type" << std::endl;
		return NULL;
	}

	// Ask for amount of credits
	std::string credits;
	std::cout << "Enter credits: ";
	getline(std::cin, credits);

	// Check if number
	if (!String::IsNumber(credits))
	{
		std::cerr << "ERROR: Invalid credits" << std::endl;
		return NULL;
	}

	double numCredits = atof(credits.c_str());
	if (numCredits > CREDITS_MAX)
	{
		std::cerr << "ERROR: Invalid credits (exceeded limit)" << std::endl;
		return NULL;
	}

	// TODO: Prompt success

	return std::make_shared<CreateTransaction>(userName, type, numCredits);
}

bool CreateHandler::IsAllowed(std::shared_ptr<User> &user)
{
	// Ensure the user is an admin
	return user != NULL && user->GetType() == kUserType_Admin;
}

bool CreateHandler::IsAvailable(std::shared_ptr<User> &user)
{
	// Ensure the user is logged in and is an admin
	return user != NULL && user->GetType() == kUserType_Admin;
}