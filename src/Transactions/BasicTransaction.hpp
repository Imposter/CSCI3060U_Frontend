#pragma once

#include "Transaction.hpp"
#include "../Config.hpp"
#include "../UserType.hpp"
#include "../Utility/ISerializer.hpp"

/**
* \brief Basic transaction containing common transaction information
*/
class BasicTransaction : public Transaction
{
    char userName[USERNAME_LENGTH];
    UserType userType;
    int credits;

public:
	/**
	* \brief Serializer for serializing and deserializing AdvertiseTransaction
	*/
	class Serializer : public ISerializer<BasicTransaction>
	{
	public:
		/**
		* \brief Serializes transaction into a string
		* \param data Transaction to serialize
		* \return String representation of transaction
		*/
		std::string Serialize(std::shared_ptr<BasicTransaction> data) override;

		/**
		* \brief Deserializes string into transaction
		* \param serializedData Data to deserialize into a transaction
		* \return Transaction from data
		*/
		std::shared_ptr<BasicTransaction> Deserialize(std::string serializedData) override;
	};

	/**
	 * \brief Initializes transaction with transaction type
	 * \param type Transaction type
	 */
	explicit BasicTransaction(TransactionType type);
};