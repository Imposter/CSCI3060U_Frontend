#pragma once

#include "Transaction.hpp"
#include "../Config.hpp"
#include "../UserType.hpp"
#include "../Utility/ISerializer.hpp"

class BidTransaction : public Transaction
{
    char itemName[ITEM_NAME_LENGTH];
    char sellerUserName[USERNAME_LENGTH];
    char buyerUserName[USERNAME_LENGTH];
    int newBid;

public:
	class Serializer : public ISerializer<BidTransaction>
	{
	public:
		std::string Serialize(std::shared_ptr<BidTransaction> data) override;
		std::shared_ptr<BidTransaction> Deserialize(std::string serializedData) override;
	};

	explicit BidTransaction();
};