#include "AdvertiseTransaction.hpp"
#include <algorithm>

std::string AdvertiseTransaction::Serializer::Serialize(std::shared_ptr<AdvertiseTransaction> data)
{
	// TODO: Implement
	return {};
}

std::shared_ptr<AdvertiseTransaction> AdvertiseTransaction::Serializer::Deserialize(std::string serializedData)
{
	// TODO: Implement
	return NULL;
}

AdvertiseTransaction::AdvertiseTransaction(const char *itemName, const char *sellerUserName, int daysToAuction, float minBid)
	: Transaction(kTransactionType_Advertise), daysToAuction(daysToAuction), minBid(minBid) 
{
	// Copy item name
	int len = strlen(itemName);
	strncpy_s(this->itemName, itemName, std::min(len, ITEM_NAME_LENGTH));

	// Copy user name
	len = strlen(sellerUserName);
	strncpy_s(this->sellerUserName, sellerUserName, std::min(len, USERNAME_LENGTH));
}