#include "BidTransaction.hpp"
#include <algorithm>

std::string BidTransaction::Serializer::Serialize(std::shared_ptr<BidTransaction> data)
{
	// TODO: Implement
	return {};
}

std::shared_ptr<BidTransaction> BidTransaction::Serializer::Deserialize(std::string serializedData)
{
	// TODO: Implement
	return NULL;
}

BidTransaction::BidTransaction(const char *itemName, const char *sellerUserName, const char *buyerUserName, float newBid)
	: Transaction(kTransactionType_Bid), newBid(newBid)
{
	// Copy item name
	int len = strlen(itemName);
	strncpy_s(this->itemName, itemName, std::min(len, ITEM_NAME_LENGTH));

	// Copy seller user name
	len = strlen(sellerUserName);
	strncpy_s(this->sellerUserName, sellerUserName, std::min(len, USERNAME_LENGTH));

	// Copy buyer user name
	len = strlen(buyerUserName);
	strncpy_s(this->buyerUserName, buyerUserName, std::min(len, USERNAME_LENGTH));
}