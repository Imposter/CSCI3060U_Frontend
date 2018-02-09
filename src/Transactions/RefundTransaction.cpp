#include "RefundTransaction.hpp"

std::string RefundTransaction::Serializer::Serialize(std::shared_ptr<RefundTransaction> data)
{
	// TODO: Implement
}

std::shared_ptr<RefundTransaction> RefundTransaction::Serializer::Deserialize(std::string serializedData)
{
	// TODO: Implement
}

RefundTransaction::RefundTransaction()
	: Transaction(kTransactionType_Refund), buyerUserName{0}, sellerUserName{0}, credits(0) {}