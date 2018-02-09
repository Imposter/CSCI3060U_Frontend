#include "BidHandler.hpp"

BidHandler::BidHandler(TransactionFile &transactionFile, UserFile &userFile, ItemFile &itemFile)
	: transactionFile(transactionFile), userFile(userFile), itemFile(itemFile) {}

TransactionType BidHandler::GetType()
{
	return kTransactionType_Bid;
}

std::string BidHandler::GetName()
{
	return "bid";
}

std::shared_ptr<Transaction> BidHandler::Handle(std::shared_ptr<User> &user)
{
	// TODO: Perform input/checks

	// TODO: When bidding, store changes to the actual item in the itemfile while working (so we can check against if the next bid is done while the app is running)

	return NULL;
}

bool BidHandler::IsAllowed(std::shared_ptr<User> &user)
{
	// TODO: Implement
	return false;
}

bool BidHandler::IsAvailable(std::shared_ptr<User> &user)
{
	// TODO: Implement
	return false;
}