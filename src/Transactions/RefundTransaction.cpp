#include "RefundTransaction.hpp"
#include "../Config.hpp"
#include "../Utility/String.hpp"
#include <algorithm>
#include <sstream>

std::string RefundTransaction::Serializer::Serialize(std::shared_ptr<RefundTransaction> data)
{
	std::stringstream stream;
	stream << GetTransactionTypeString(data->GetType()) << ' ';
	stream << String::PadRight(data->buyerUserName, ' ', USERNAME_LENGTH) << ' ';
	stream << String::PadRight(data->sellerUserName, ' ', USERNAME_LENGTH) << ' ';
	stream << String::PadLeft(String::Format("%.2f", data->credits), '0', CREDITS_LENGTH);

	return stream.str();
}

std::shared_ptr<RefundTransaction> RefundTransaction::Serializer::Deserialize(std::string serializedData)
{
	std::stringstream stream(serializedData);

	std::string buyerUserName;
	std::string sellerUserName;
	double credits;

	// Ignore type
	stream.ignore();

	stream >> buyerUserName;
	stream >> sellerUserName;
	stream >> credits;

	return std::make_shared<RefundTransaction>(buyerUserName, sellerUserName, credits);
}

RefundTransaction::RefundTransaction(const std::string &buyerUserName, const std::string &sellerUserName, double credits)
	: Transaction(kTransactionType_Refund), buyerUserName(buyerUserName), sellerUserName(sellerUserName), credits(credits) {}

const std::string &RefundTransaction::GetBuyerUserName() const
{
	return buyerUserName;
}

const std::string &RefundTransaction::GetSellerUserName() const
{
	return sellerUserName;
}

const double &RefundTransaction::GetCredits() const
{
	return credits;
}
