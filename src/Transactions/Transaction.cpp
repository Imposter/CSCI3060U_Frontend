#include "Transaction.hpp"

Transaction::Transaction(TransactionType type)
	: mType(type) {}

const TransactionType &Transaction::GetType() const
{
	return mType;
}