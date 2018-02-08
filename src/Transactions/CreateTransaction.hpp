#pragma once

#include "Transaction.hpp"
#include "../Config.hpp"
#include "../UserType.hpp"
#include "../Utility/ISerializer.hpp"

class CreateTransaction : public Transaction
{
    char userName[USERNAME_LENGTH];
    UserType userType;
    int credits;

public:
	class Serializer : public ISerializer<CreateTransaction>
	{
	public:
		std::string Serialize(CreateTransaction data) override;
		CreateTransaction Deserialize(std::string serializedData) override;
	};

	explicit CreateTransaction();
};