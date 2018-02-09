#pragma once

#include "Transaction.hpp"
#include "../Config.hpp"
#include "../UserType.hpp"
#include "../Utility/ISerializer.hpp"

class BasicTransaction : public Transaction
{
    char userName[USERNAME_LENGTH];
    UserType userType;
    int credits;

public:
	class Serializer : public ISerializer<BasicTransaction>
	{
	public:
		std::string Serialize(std::shared_ptr<BasicTransaction> data) override;
		std::shared_ptr<BasicTransaction> Deserialize(std::string serializedData) override;
	};

	explicit BasicTransaction(TransactionType type);
};