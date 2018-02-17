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
