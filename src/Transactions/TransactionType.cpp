#include "TransactionType.hpp"
#include "../Utility/String.hpp"

std::string GetTransactionTypeString(TransactionType type)
{
	return String::PadLeft(std::to_string((int)type), '0', 2);
}