#include "AddCreditHandler.hpp"
#include "../Transactions/AddCreditTransaction.hpp"
#include "../Transactions/RefundTransaction.hpp"
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
	if (user->GetType() == kUserType_Admin)
	{
		std::cout << "Enter username: ";
		getline(std::cin, userName);
	}
	else
	{
		userName = user->GetName();
	}

	// Check if account exists in the user file
	auto userAccount = mUserFile.GetUserByName(userName);
	if (!userAccount)
	{
		std::cerr << "ERROR: User does not exist" << std::endl;
		return NULL;
	}

	// Check if the user is deleted the same day
	for (const auto &t : mTransactionFile.GetTransactions(kTransactionType_Delete))
	{
		const auto transaction = PointerCast::Reinterpret<BasicTransaction>(t);
		if (transaction->GetUserName() == userName)
		{
			std::cerr << "ERROR: User does not exist" << std::endl;
			return NULL;
		}
	}

	// Ask for amount of credits
	std::string credits;
	std::cout << "Enter credits to add: ";
	getline(std::cin, credits);

	// Check if number
	if (!String::IsNumber(credits))
	{
		std::cerr << "ERROR: Invalid credits" << std::endl;
		return NULL;
	}

	// Check if it exceeds max credits in the current transaction, only if the user is not an admin
	auto numCredits = strtod(credits.c_str(), NULL);
	if (user->GetType() != kUserType_Admin && user->GetAddedCredits() + numCredits > CREDITS_SESSION_MAX)
	{
		std::cerr << "ERROR: Credits exceed limit of " << CREDITS_SESSION_MAX << " credits per session" << std::endl;
		return NULL;
	}	

	// Check if the credit addition would exceed max balance
	auto newCredits = userAccount->GetCredits() + numCredits;
	if (newCredits > CREDITS_MAX)
	{
		std::cout << "ERROR: Credits exceed limit of " << CREDITS_MAX << std::endl;
		return NULL;
	}

	// Update user's credits
	userAccount->SetCredits(newCredits);
	userAccount->AddCredits(numCredits);

	// Prompt success
	std::cout << "Added " << numCredits << " credits to " << userName << std::endl;

	return std::make_shared<AddCreditTransaction>(userAccount->GetName(), userAccount->GetType(), newCredits);
}

bool AddCreditHandler::IsAvailable(std::shared_ptr<User> &user)
{
	return user != NULL;
}
