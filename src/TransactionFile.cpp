#include "TransactionFile.hpp"
#include "Utility/PointerCast.hpp"

TransactionFile::TransactionFile(std::string fileName)
	: File(fileName) {}

void TransactionFile::AddSerializer(TransactionType type, std::shared_ptr<ISerializer<Transaction>> serializer)
{
	serializers.insert({ type, PointerCast::Reinterpret<ISerializer<Transaction>>(serializer) });
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
		const std::string typeString = line.substr(2);
		const std::string data = line.substr(3);

		if (typeString == GetTransactionTypeString(type))
		{
			result.push_back(serializer->Deserialize(data));
		}
	}

	return result;
}

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