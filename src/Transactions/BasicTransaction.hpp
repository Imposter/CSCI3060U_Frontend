#pragma once

#include "Transaction.hpp"
#include "../UserType.hpp"
#include "../Utility/ISerializer.hpp"

/**
* \brief Basic transaction containing common transaction information
*/
class BasicTransaction : public Transaction
{
    std::string userName;
    UserType userType;
	float credits;

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
	explicit BasicTransaction(TransactionType type, const std::string &userName, UserType userType, float credits);

	/**
	 * \brief Gets user name
	 * \return User name
	 */
	const std::string &GetUserName() const;

	/**
	 * \brief Gets user's type
	 * \return User type
	 */
	const UserType &GetUserType() const;

	/**
	 * \brief Gets user's credits
	 * \return Account credits
	 */
	const float &GetCredits() const;
};