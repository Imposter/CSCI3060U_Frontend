#pragma once

#include "TransactionType.hpp"

/**
 * \brief Used for storing and interpreting transaction information
 */
class Transaction
{
	TransactionType type;

public:
	/**
	 * \brief Initialize transaction with its type
	 * \param type Transaction type
	 */
	explicit Transaction(TransactionType type);

	/**
	 * \brief Returns type of transaction
	 * \return Transaction type
	 */
	const TransactionType &GetType() const;
};