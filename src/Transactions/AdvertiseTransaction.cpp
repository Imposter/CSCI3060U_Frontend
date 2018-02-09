#include "AdvertiseTransaction.hpp"

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

AdvertiseTransaction::AdvertiseTransaction()
	: Transaction(kTransactionType_Advertise), itemName{0}, sellerUserName{0}, daysToAuction(0), minBid(0) {}