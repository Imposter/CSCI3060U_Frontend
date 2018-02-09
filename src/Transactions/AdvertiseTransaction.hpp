#pragma once

#include "Transaction.hpp"
#include "../Config.hpp"
#include "../UserType.hpp"
#include "../Utility/ISerializer.hpp"

class AdvertiseTransaction : public Transaction
{
    char itemName[ITEM_NAME_LENGTH];
	char sellerUserName[USERNAME_LENGTH];
	int daysToAuction;
    int minBid;

public:
	class Serializer : public ISerializer<AdvertiseTransaction>
	{
	public:
		std::string Serialize(std::shared_ptr<AdvertiseTransaction> data) override;
		std::shared_ptr<AdvertiseTransaction> Deserialize(std::string serializedData) override;
	};

	explicit AdvertiseTransaction();
};