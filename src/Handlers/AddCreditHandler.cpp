#include "AddCreditHandler.hpp"
#include "../Transactions/AddCreditTransaction.hpp"
#include "../Config.hpp"
#include "../Utility/String.hpp"
#include <iostream>
#include <vector>

AddCreditHandler::AddCreditHandler(TransactionFile &transactionFile, UserFile &userFile)
	: mTransactionFile(transactionFile), mUserFile(userFile) {}

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
	// Get username
	std::string userName;
	if(user->GetType() == kUserType_Admin) {
		std::cout << "Enter username: ";
		getline(std::cin, userName);
	} else {
		userName = user->GetName();
	}
	
	// Check if account exists in the user file
	if (!mUserFile.GetUserByName(userName))
	{
		std::cerr << "ERROR: User does not exist" << std::endl;
		return NULL;
	}

	// Ask for amount of credits
	std::string credits;
	std::cout << "Enter credits to return: ";
	getline(std::cin, credits);

	// Check if number
	if (!String::IsNumber(credits))
	{
		std::cerr << "ERROR: Invalid credits" << std::endl;
		return NULL;
	}

	// Check if it exceeds max credits in the current transaction
	// Admins can override this limit
	auto numCredits = strtod(credits.c_str(), NULL);
	if ((numCredits > CREDITS_ADDCREDIT_MAX) && (user->GetType() != kUserType_Admin))
	{
		std::cerr << "ERROR: Credits exceed limit of " << CREDITS_ADDCREDIT_MAX << std::endl;
		return NULL;
	}

	//TODO: ???

	// Check if the credit addition would overflow max balance
	auto newCredits = mUserFile.GetUserByName(userName)->GetCredits() + numCredits;
	if(newCredits > CREDITS_MAX) {
		std::cout << "ERROR: User credits would exceed limit of " << CREDITS_MAX << std::endl;
	}

	return std::make_shared<AddCreditTransaction>(userName, mUserFile.GetUserByName(userName)->GetType(), newCredits);
}

bool AddCreditHandler::IsAvailable(std::shared_ptr<User> &user)
{
	return user != NULL;
}