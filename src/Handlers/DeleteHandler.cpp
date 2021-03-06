#include "DeleteHandler.hpp"
#include "../Transactions/BasicTransaction.hpp"
#include "../Transactions/DeleteTransaction.hpp"
#include "../Utility/String.hpp"
#include <iostream>
#include <algorithm>

DeleteHandler::DeleteHandler(TransactionFile &transactionFile, UserFile &userFile)
	: mTransactionFile(transactionFile), mUserFile(userFile) {}

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
	const auto userAccount = mUserFile.GetUserByName(userName);
	if (!userAccount)
	{
		std::cerr << "ERROR: User does not exist" << std::endl;
		return NULL;
	}

	// Check if the account is already deleted
	for (const auto &t : mTransactionFile.GetTransactions(kTransactionType_Delete))
	{
		const auto transaction = PointerCast::Reinterpret<BasicTransaction>(t);
		if (transaction->GetUserName() == userName)
		{
			std::cerr << "ERROR: User does not exist" << std::endl;
			return NULL;
		}
	}

	// Remove user from users file
	auto users = mUserFile.GetUsers();
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