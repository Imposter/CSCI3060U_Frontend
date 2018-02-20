#include "DeleteHandler.hpp"

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
    // TODO: Perform inputs/checks

	// TODO/NOTE: Do not delete users that were created on the same day, as they are not present in the current users file
	// TODO/NOTE: Do not allow any operations on new users/items that haven't been through the backend first

	return NULL;
}

bool DeleteHandler::IsAllowed(std::shared_ptr<User> &user)
{
	// Ensure the user is an admin
	return user->GetType() == kUserType_Admin;
}

bool DeleteHandler::IsAvailable(std::shared_ptr<User> &user)
{
	// Ensure the user is logged in and is an admin
	return user != NULL && user->GetType() == kUserType_Admin;
}