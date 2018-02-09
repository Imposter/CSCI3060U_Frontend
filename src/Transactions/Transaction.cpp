#include "Transaction.hpp"

Transaction::Transaction(TransactionType type)
	: type(type) {}

const TransactionType &Transaction::GetType() const
{
	return type;
}