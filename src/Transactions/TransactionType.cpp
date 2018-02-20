#include "TransactionType.hpp"
#include "../Utility/String.hpp"

std::string GetTransactionTypeString(TransactionType type)
{
	return String::PadLeft(std::to_string(static_cast<int>(type)), '0', 2);
}