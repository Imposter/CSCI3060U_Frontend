#pragma once

#include "Transaction.hpp"
#include "../Config.hpp"
#include "../UserType.hpp"
#include "../Utility/ISerializer.hpp"

class RefundTransaction : public Transaction
{
    char buyerUserName[USERNAME_LENGTH];
    char sellerUserName[USERNAME_LENGTH];
    int credits;

public:
	class Serializer : public ISerializer<RefundTransaction>
	{
	public:
		std::string Serialize(std::shared_ptr<RefundTransaction> data) override;
		std::shared_ptr<RefundTransaction> Deserialize(std::string serializedData) override;
	};

	explicit RefundTransaction();
};