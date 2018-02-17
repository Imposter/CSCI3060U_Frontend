#pragma once

#include "Transaction.hpp"
#include "../Config.hpp"
#include "../UserType.hpp"
#include "../Utility/ISerializer.hpp"

/**
* \brief Transaction for advertisements containing relevant information about the advertisement
*/
class AdvertiseTransaction : public Transaction
{
    char itemName[ITEM_NAME_LENGTH];
	char sellerUserName[USERNAME_LENGTH];
	int daysToAuction;
	float minBid;

public:
	/**
	* \brief Serializer for serializing and deserializing AdvertiseTransaction
	*/
	class Serializer : public ISerializer<AdvertiseTransaction>
	{
	public:
		/**
		* \brief Serializes transaction into a string
		* \param data Transaction to serialize
		* \return String representation of transaction
		*/
		std::string Serialize(std::shared_ptr<AdvertiseTransaction> data) override;

		/**
		* \brief Deserializes string into transaction
		* \param serializedData Data to deserialize into a transaction
		* \return Transaction from data
		*/
		std::shared_ptr<AdvertiseTransaction> Deserialize(std::string serializedData) override;
	};

	/**
	* \brief Default constructor initializing transaction with advertise type
	*/
	explicit AdvertiseTransaction(const char *itemName, const char *sellerUserName, int daysToAuction, float minBid);
};