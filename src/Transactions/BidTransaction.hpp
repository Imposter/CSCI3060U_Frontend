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
    std::string itemName;
	std::string sellerUserName;
	std::string buyerUserName;
	double newBid;

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
	explicit BidTransaction(const std::string &itemName, const std::string &sellerUserName, const std::string &buyerUserName, double newBid);

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
	* \brief Gets buyer's user name
	* \return Buyer's user name
	*/
	const std::string &GetBuyerUserName() const;

	/**
	* \brief Gets the item's new bid
	* \return New bid
	*/
	const double &GetNewBid() const;
};