#include "DeleteHandler.hpp"
#include "../Config.hpp"
#include "../Transactions/BasicTransaction.hpp"
#include "../Transactions/DeleteTransaction.hpp"
#include "../Utility/String.hpp"
#include <iostream>
#include <algorithm>

DeleteHandler::DeleteHandler(TransactionFile &transactionFile, UserFile &userFile)
	: transactionFile(transactionFile), userFile(userFile) {}

TransactionType DeleteHandler::GetType()
{
	return kTransactionType_Delete;
}

std::string DeleteHandler::GetName()
{
	return "delete";
}

std::shared_ptr<Transaction> DeleteHandler::Handle(std::shared_ptr<User> &user)
{
	// Get username
	std::string userName;
	std::cout << "Enter username: ";
	getline(std::cin, userName);

	// Check if the username refers to the current user
	if (userName == user->GetName())
	{
		std::cerr << "ERROR: Cannot delete active user" << std::endl;
		return NULL;
	}

	// Check if account exists in the user file
	auto userAccount = userFile.GetUserByName(userName);
	if (!userAccount)
	{
		std::cerr << "ERROR: User does not exist" << std::endl;
		return NULL;
	}

	// Check if the account is already deleted
	for (auto t : transactionFile.GetTransactions(kTransactionType_Delete))
	{
		auto transaction = PointerCast::Reinterpret<BasicTransaction>(t);
		if (transaction->GetUserName() == userName)
		{
			std::cerr << "ERROR: User does not exist" << std::endl;
			return NULL;
		}
	}

	// Remove user from users file
	auto users = userFile.GetUsers();
	users.erase(remove(users.begin(), users.end(), userAccount), users.end());

	// Prompt success
	std::cout << "Deleted user " << userName << " of type " << GetUserTypeLongString(userAccount->GetType()) << " with " << String::Format("%.2f", userAccount->GetCredits()) << " credits" << std::endl;

	// Return transaction
	return std::make_shared<DeleteTransaction>(userAccount->GetName(), userAccount->GetType(), userAccount->GetCredits());
}

bool DeleteHandler::IsAvailable(std::shared_ptr<User> &user)
{
	// Ensure the user is logged in and is an admin
	return user != NULL && user->GetType() == kUserType_Admin;
}