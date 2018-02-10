#pragma once

#include "Transaction.hpp"
#include "../Config.hpp"
#include "../UserType.hpp"
#include "../Utility/ISerializer.hpp"

/**
* \brief Transaction for bids containing relevant information about the bid
*/
class BidTransaction : public Transaction
{
    char itemName[ITEM_NAME_LENGTH];
    char sellerUserName[USERNAME_LENGTH];
    char buyerUserName[USERNAME_LENGTH];
    int newBid;

public:
	/**
	* \brief Serializer for serializing and deserializing AdvertiseTransaction
	*/
	class Serializer : public ISerializer<BidTransaction>
	{
	public:
		/**
		* \brief Serializes transaction into a string
		* \param data Transaction to serialize
		* \return String representation of transaction
		*/
		std::string Serialize(std::shared_ptr<BidTransaction> data) override;
		
		/**
		* \brief Deserializes string into transaction
		* \param serializedData Data to deserialize into a transaction
		* \return Transaction from data
		*/
		std::shared_ptr<BidTransaction> Deserialize(std::string serializedData) override;
	};

	/**
	* \brief Default constructor initializing transaction with bid type
	*/
	explicit BidTransaction();
};