#pragma once

#include "Transaction.hpp"
#include "../Config.hpp"
#include "../UserType.hpp"
#include "../Utility/ISerializer.hpp"

/**
 * \brief Transaction for refunds containing relevant information about the refund
 */
class RefundTransaction : public Transaction
{
    char buyerUserName[USERNAME_LENGTH];
    char sellerUserName[USERNAME_LENGTH];
    int credits;

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
	explicit RefundTransaction();
};