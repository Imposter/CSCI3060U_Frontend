#pragma once

#include "Transaction.hpp"
#include "../UserType.hpp"
#include "../Utility/ISerializer.hpp"

/**
 * \brief Transaction for refunds containing relevant information about the refund
 */
class RefundTransaction : public Transaction
{
	std::string mBuyerUserName;
	std::string mSellerUserName;
	double mCredits;

public:
	/**
	 * \brief Serializer for serializing and deserializing RefundTransaction
	 */
	class Serializer : public ISerializer<RefundTransaction>
	{
	public:
		/**
		 * \brief Serializes transaction into a string
		 * \param data Transaction to serialize
		 * \return String representation of transaction
		 */
		std::string Serialize(std::shared_ptr<RefundTransaction> data) override;

		/**
		 * \brief Deserializes string into transaction
		 * \param serializedData Data to deserialize into a transaction
		 * \return Transaction from data
		 */
		std::shared_ptr<RefundTransaction> Deserialize(std::string serializedData) override;
	};

	/**
	 * \brief Default constructor initializing transaction with refund type
	 */
	explicit RefundTransaction(const std::string &buyerUserName, const std::string &sellerUserName, double credits);

	/**
	* \brief Gets buyer's user name
	* \return Buyer's user name
	*/
	const std::string &GetBuyerUserName() const;

	/**
	* \brief Gets seller's user name
	* \return Seller's user name
	*/
	const std::string &GetSellerUserName() const;

	/**
	* \brief Gets the refunded credits
	* \return Refunded credits
	*/
	const double &GetCredits() const;
};