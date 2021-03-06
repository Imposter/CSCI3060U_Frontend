#pragma once

#include "File.hpp"
#include "Transactions/Transaction.hpp"
#include "Utility/ISerializer.hpp"
#include "Utility/PointerCast.hpp"
#include <map>
#include <memory>

/**
* \brief Daily transactions file used to store transactions applied to the system for the day
*/
class TransactionFile : public File 
{
	std::map<TransactionType, std::shared_ptr<ISerializer<Transaction>>> mSerializers;

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
	template<typename TTransaction = Transaction>
	void AddSerializer(TransactionType type, std::shared_ptr<ISerializer<TTransaction>> serializer)
	{
		mSerializers.insert({ type, PointerCast::Reinterpret<ISerializer<Transaction>>(serializer) });
	}

	/**
	 * \brief Serializes and writes specified transaction to the file
	 * \param transaction Transaction to write
	 */
	void WriteTransaction(std::shared_ptr<Transaction> transaction);

	/**
	* \brief Returns all of the transactions made of a certain type
	* \param type Transaction type to get transaction for
	* \return All transactions of the specified type
	*/
	std::vector<std::shared_ptr<Transaction>> GetTransactions(TransactionType type);

	/**
	* \brief Returns all of the transactions made of the specified types
	* \param types Transaction typse to get transactions for
	* \return All transactions of the specified type
	*/
	std::vector<std::shared_ptr<Transaction>> GetTransactions(std::vector<TransactionType> types);
};