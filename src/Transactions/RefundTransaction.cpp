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

	std::string type;
	std::string buyerUserName;
	std::string sellerUserName;
	double credits;

	stream >> type;
	stream.ignore();

	buyerUserName.resize(USERNAME_LENGTH);
	stream.read(const_cast<char *>(buyerUserName.c_str()), USERNAME_LENGTH);
	buyerUserName = String::TrimRight(buyerUserName);
	stream.ignore();

	sellerUserName.resize(USERNAME_LENGTH);
	stream.read(const_cast<char *>(sellerUserName.c_str()), USERNAME_LENGTH);
	sellerUserName = String::TrimRight(sellerUserName);
	stream.ignore();

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
