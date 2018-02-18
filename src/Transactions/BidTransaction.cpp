#include "BidTransaction.hpp"
#include "../Config.hpp"
#include "../Utility/String.hpp"
#include <algorithm>
#include <sstream>

std::string BidTransaction::Serializer::Serialize(std::shared_ptr<BidTransaction> data)
{
	std::stringstream stream;
	stream << GetTransactionTypeString(data->GetType()) << ' ';
	stream << String::PadRight(data->itemName, ' ', ITEM_NAME_LENGTH) << ' ';
	stream << String::PadRight(data->sellerUserName, ' ', USERNAME_LENGTH) << ' ';
	stream << String::PadRight(data->buyerUserName, ' ', USERNAME_LENGTH) << ' ';
	stream << String::PadLeft(String::Format("%.2f", data->newBid), '0', 6);

	return stream.str();
}

std::shared_ptr<BidTransaction> BidTransaction::Serializer::Deserialize(std::string serializedData)
{
	std::stringstream stream(serializedData);

	std::string itemName;
	std::string sellerUserName;
	std::string buyerUserName;
	float newBid;

	// Ignore type
	stream.ignore();

	stream >> itemName;
	stream >> sellerUserName;
	stream >> buyerUserName;
	stream >> newBid;

	return std::make_shared<BidTransaction>(itemName, sellerUserName, sellerUserName, newBid);
}

BidTransaction::BidTransaction(const std::string &itemName, const std::string &sellerUserName, const std::string &buyerUserName, float newBid)
	: Transaction(kTransactionType_Bid), itemName(itemName), sellerUserName(sellerUserName), buyerUserName(buyerUserName), newBid(newBid) {}

const std::string &BidTransaction::GetItemName() const
{
	return itemName;
}

const std::string &BidTransaction::GetSellerUserName() const
{
	return sellerUserName;
}

const std::string &BidTransaction::GetBuyerUserName() const
{
	return buyerUserName;
}

const float &BidTransaction::GetNewBid() const
{
	return newBid;
}