#pragma once

#include "TransactionType.hpp"

class Transaction
{
	TransactionType type;

public:
	explicit Transaction(TransactionType type);

	const TransactionType &GetType() const;
};