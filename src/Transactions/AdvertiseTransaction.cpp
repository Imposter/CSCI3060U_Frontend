#include "AdvertiseTransaction.hpp"
#include "../Config.hpp"
#include "../Utility/String.hpp"
#include <algorithm>
#include <sstream>

std::string AdvertiseTransaction::Serializer::Serialize(std::shared_ptr<AdvertiseTransaction> data)
{
	std::stringstream stream;
	stream << GetTransactionTypeString(data->GetType()) << ' ';
	stream << String::PadRight(data->itemName, ' ', ITEM_NAME_LENGTH) << ' ';
	stream << String::PadRight(data->sellerUserName, ' ', USERNAME_LENGTH) << ' ';
	stream << String::PadLeft(std::to_string(data->daysToAuction), '0', 3) << ' ';
	stream << String::PadLeft(String::Format("%.2f", data->minBid), '0', ITEM_PRICE_LENGTH);

	return stream.str();
}

std::shared_ptr<AdvertiseTransaction> AdvertiseTransaction::Serializer::Deserialize(std::string serializedData)
{
	std::stringstream stream(serializedData);

	std::string type;
	std::string itemName;
	std::string sellerUserName;
	int daysToAuction;
	double minBid;

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

	stream >> daysToAuction;
	stream >> minBid;

	return std::make_shared<AdvertiseTransaction>(itemName, sellerUserName, daysToAuction, minBid);
}

AdvertiseTransaction::AdvertiseTransaction(const std::string &itemName, const std::string &sellerUserName, int daysToAuction, double minBid)
	: Transaction(kTransactionType_Advertise), itemName(itemName), sellerUserName(sellerUserName), daysToAuction(daysToAuction), minBid(minBid) {}

const std::string &AdvertiseTransaction::GetItemName() const
{
	return itemName;
}

const std::string &AdvertiseTransaction::GetSellerUserName() const
{
	return sellerUserName;
}

const int &AdvertiseTransaction::GetDaysToAuction() const
{
	return daysToAuction;
}

const double &AdvertiseTransaction::GetMinimumBid() const
{
	return minBid;
}
