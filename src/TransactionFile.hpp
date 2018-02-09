#pragma once

#include "File.hpp"
#include "Transactions/Transaction.hpp"
#include "Utility/ISerializer.hpp"
#include <map>
#include <memory>

/**
* \brief Daily transactions file used to store transactions applied to the system for the day
*/
class TransactionFile : public File 
{
	std::map<TransactionType, std::shared_ptr<ISerializer<Transaction>>> serializers;

public:
	/**
	 * \brief Initializes transaction file with specified file path
	 * \param fileName File path
	 */
	explicit TransactionFile(std::string fileName);

	/**
	 * \brief Stores the serializer for the specified transaction type
	 * \param type Transaction to which the serializer is used for 
	 * \param serializer Serializer used to serialize or deserialize transaction
	 */
	void AddSerializer(TransactionType type, std::shared_ptr<ISerializer<Transaction>> serializer);

	/**
	 * \brief Returns all of the transactions made of a certain type
	 * \param type Transaction type to get transaction for
	 * \return All transactions of the specified type
	 */
	std::vector<std::shared_ptr<Transaction>> GetTransactions(TransactionType type);

	/**
	 * \brief Serializes and writes specified transaction to the file
	 * \param transaction Transaction to write
	 */
	void WriteTransaction(std::shared_ptr<Transaction> transaction);
};