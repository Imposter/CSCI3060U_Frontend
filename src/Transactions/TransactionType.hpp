#pragma once

#include <string>

enum TransactionType
{
	kTransactionType_None = -1,
	kTransactionType_Login = 10,
	kTransactionType_Logout = 00,
	kTransactionType_Create = 01,
	kTransactionType_Delete = 02,
	kTransactionType_Advertise = 03,
	kTransactionType_Bid = 04,
	kTransactionType_Refund = 05,
	kTransactionType_AddCredit = 06
};

/**
 * \brief Converts transaction type to a string
 * \param type Transaction type to convert to string
 * \return Transaction type in its string representation
 */
std::string GetTransactionTypeString(TransactionType type);