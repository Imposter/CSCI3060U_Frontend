#include "TransactionFile.hpp"

TransactionFile::TransactionFile(std::string fileName)
	: File(fileName) {}

void TransactionFile::WriteTransaction(std::shared_ptr<Transaction> transaction)
{
	// Go to the end of the file
	Forward();

	// Get serializer for type
	std::vector<std::shared_ptr<Transaction>> result;
	if (mSerializers.find(transaction->GetType()) == mSerializers.end())
		return;

	auto serializer = mSerializers[transaction->GetType()];

	// Serialize and write transaction string
	WriteLine(serializer->Serialize(transaction));
}

std::vector<std::shared_ptr<Transaction>> TransactionFile::GetTransactions(TransactionType type)
{
	// Get serializer for type
	std::vector<std::shared_ptr<Transaction>> result;
	if (mSerializers.find(type) == mSerializers.end())
		return result;

	auto serializer = mSerializers[type];

	// Rewind file
	Rewind();

	// Read and return result
	auto lines = ReadLines();
	for (const auto &line : lines)
	{
		// Skip invalid lines
		if (line.empty())
			continue;

		const auto typeString = line.substr(0, 2);

		if (typeString == GetTransactionTypeString(type))
			result.push_back(serializer->Deserialize(line));
	}

	return result;
}