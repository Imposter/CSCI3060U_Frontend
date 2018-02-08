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

// NOTE: Untested
std::string GetTransactionTypeString(TransactionType type);