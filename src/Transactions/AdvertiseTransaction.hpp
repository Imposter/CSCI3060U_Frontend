#pragma once

#include "Transaction.hpp"
#include "../UserType.hpp"
#include "../Utility/ISerializer.hpp"

/**
* \brief Transaction for advertisements containing relevant information about the advertisement
*/
class AdvertiseTransaction : public Transaction
{
	std::string itemName;
	std::string sellerUserName;
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
	explicit AdvertiseTransaction(const std::string &itemName, const std::string &sellerUserName, int daysToAuction, float minBid);

	/**
	* \brief Gets item name
	* \return Item name
	*/
	const std::string &GetItemName() const;

	/**
	* \brief Gets seller's user name
	* \return Seller's user name
	*/
	const std::string &GetSellerUserName() const;

	/**
	* \brief Gets days left to auction
	* \return Days left to the auction's end
	*/
	const int &GetDaysToAuction() const;

	/**
	* \brief Gets the item's minimum bid
	* \return Minimum bid
	*/
	const float &GetMinimumBid() const;
};