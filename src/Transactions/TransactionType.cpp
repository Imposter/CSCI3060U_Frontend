#include "TransactionType.hpp"
#include <sstream>
#include <iomanip>

std::string GetTransactionTypeString(TransactionType type)
{
	std::stringstream stream;
	stream << std::setfill('0') << std::setw(2) << type;

	return stream.str();
}