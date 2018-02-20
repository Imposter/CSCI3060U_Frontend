#include "TransactionFile.hpp"

TransactionFile::TransactionFile(std::string fileName)
	: File(fileName) {}

void TransactionFile::WriteTransaction(std::shared_ptr<Transaction> transaction)
{
	// Go to the end of the file
	Forward();

	// Get serializer for type
	std::vector<std::shared_ptr<Transaction>> result;
	if (serializers.find(transaction->GetType()) == serializers.end())
		return;

	auto serializer = serializers[transaction->GetType()];

	// Serialize and write transaction string
	WriteLine(serializer->Serialize(transaction));
}

std::vector<std::shared_ptr<Transaction>> TransactionFile::GetTransactions(TransactionType type)
{
	// Get serializer for type
	std::vector<std::shared_ptr<Transaction>> result;
	if (serializers.find(type) == serializers.end())
		return result;

	auto serializer = serializers[type];

	// Rewind file
	Rewind();

	// Read and return result
	auto lines = ReadLines();
	for (auto line : lines)
	{
		// Skip invalid lines
		if (line.empty())
			continue;

		auto typeString = line.substr(0, 2);

		if (typeString == GetTransactionTypeString(type))
			result.push_back(serializer->Deserialize(line));
	}

	return result;
}