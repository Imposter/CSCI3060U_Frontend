#include "AdvertiseHandler.hpp"

AdvertiseHandler::AdvertiseHandler(TransactionFile &transactionFile, ItemFile &itemFile)
	: transactionFile(transactionFile), itemFile(itemFile) {}

TransactionType AdvertiseHandler::GetType()
{
	return kTransactionType_Advertise;
}

std::string AdvertiseHandler::GetName()
{
	return "advertise";
}

std::shared_ptr<Transaction> AdvertiseHandler::Handle(std::shared_ptr<User> &user)
{
	// TODO: Perform input/checks

	return NULL;
}

bool AdvertiseHandler::IsAllowed(std::shared_ptr<User> &user)
{
	// TODO: Implement
}

bool AdvertiseHandler::IsAvailable(std::shared_ptr<User> &user)
{
	// TODO: Implement
}