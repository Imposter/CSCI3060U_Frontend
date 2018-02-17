#include "RefundTransaction.hpp"
#include <algorithm>

std::string RefundTransaction::Serializer::Serialize(std::shared_ptr<RefundTransaction> data)
{
	// TODO: Implement
	return {};
}

std::shared_ptr<RefundTransaction> RefundTransaction::Serializer::Deserialize(std::string serializedData)
{
	// TODO: Implement
	return NULL;
}

RefundTransaction::RefundTransaction(const char *buyerUserName, const char *sellerUserName, float credits)
	: Transaction(kTransactionType_Refund), credits(credits)
{
	// Copy buyer user name
	int len = strlen(buyerUserName);
	strncpy_s(this->buyerUserName, buyerUserName, std::min(len, USERNAME_LENGTH));

	// Copy seller user name
	len = strlen(sellerUserName);
	strncpy_s(this->sellerUserName, sellerUserName, std::min(len, USERNAME_LENGTH));
}