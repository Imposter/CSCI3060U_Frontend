#include "AdvertiseTransaction.hpp"

std::string AdvertiseTransaction::Serializer::Serialize(std::shared_ptr<AdvertiseTransaction> data)
{
	// TODO: Implement
}

std::shared_ptr<AdvertiseTransaction> AdvertiseTransaction::Serializer::Deserialize(std::string serializedData)
{
	// TODO: Implement
}

AdvertiseTransaction::AdvertiseTransaction()
	: Transaction(kTransactionType_Advertise), itemName{0}, sellerUserName{0}, daysToAuction(0), minBid(0) {}