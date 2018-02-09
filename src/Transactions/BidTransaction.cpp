#include "BidTransaction.hpp"

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

BidTransaction::BidTransaction()
	: Transaction(kTransactionType_Bid), itemName{0}, sellerUserName{0}, buyerUserName{0}, newBid(0) {}