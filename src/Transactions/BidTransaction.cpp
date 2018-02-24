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
	stream << String::PadLeft(String::Format("%.2f", data->newBid), '0', ITEM_PRICE_LENGTH);

	return stream.str();
}

std::shared_ptr<BidTransaction> BidTransaction::Serializer::Deserialize(std::string serializedData)
{
	std::stringstream stream(serializedData);

	std::string type;
	std::string itemName;
	std::string sellerUserName;
	std::string buyerUserName;
	double newBid;

	stream >> type;
	stream.ignore();

	itemName.resize(ITEM_NAME_LENGTH);
	stream.read(const_cast<char *>(itemName.c_str()), ITEM_NAME_LENGTH);
	itemName = String::TrimRight(itemName);
	stream.ignore();

	sellerUserName.resize(USERNAME_LENGTH);
	stream.read(const_cast<char *>(sellerUserName.c_str()), USERNAME_LENGTH);
	sellerUserName = String::TrimRight(sellerUserName);
	stream.ignore();

	buyerUserName.resize(USERNAME_LENGTH);
	stream.read(const_cast<char *>(buyerUserName.c_str()), USERNAME_LENGTH);
	buyerUserName = String::TrimRight(buyerUserName);
	stream.ignore();

	stream >> newBid;

	return std::make_shared<BidTransaction>(itemName, sellerUserName, sellerUserName, newBid);
}

BidTransaction::BidTransaction(const std::string &itemName, const std::string &sellerUserName, const std::string &buyerUserName, double newBid)
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

const double &BidTransaction::GetNewBid() const
{
	return newBid;
}