#include "AdvertiseTransaction.hpp"
#include "../Config.hpp"
#include "../Utility/String.hpp"
#include <sstream>

std::string AdvertiseTransaction::Serializer::Serialize(std::shared_ptr<AdvertiseTransaction> data)
{
	std::stringstream stream;
	stream << GetTransactionTypeString(data->GetType()) << ' ';
	stream << String::PadRight(data->mItemName, ' ', ITEM_NAME_LENGTH) << ' ';
	stream << String::PadRight(data->mSellerUserName, ' ', USERNAME_LENGTH) << ' ';
	stream << String::PadLeft(std::to_string(data->mDaysToAuction), '0', 3) << ' ';
	stream << String::PadLeft(String::Format("%.2f", data->mMinBid), '0', ITEM_PRICE_LENGTH);

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
	: Transaction(kTransactionType_Advertise), mItemName(itemName), mSellerUserName(sellerUserName), mDaysToAuction(daysToAuction), mMinBid(minBid) {}

const std::string &AdvertiseTransaction::GetItemName() const
{
	return mItemName;
}

const std::string &AdvertiseTransaction::GetSellerUserName() const
{
	return mSellerUserName;
}

const int &AdvertiseTransaction::GetDaysToAuction() const
{
	return mDaysToAuction;
}

const double &AdvertiseTransaction::GetMinimumBid() const
{
	return mMinBid;
}
