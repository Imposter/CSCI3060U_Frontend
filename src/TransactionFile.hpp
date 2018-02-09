#pragma once

#include "File.hpp"
#include "Transactions/Transaction.hpp"
#include "Utility/ISerializer.hpp"
#include <map>
#include <memory>

class TransactionFile : public File 
{
	std::map<TransactionType, std::shared_ptr<ISerializer<Transaction>>> serializers;

public:
	TransactionFile(std::string fileName);

	void AddSerializer(TransactionType type, std::shared_ptr<ISerializer<Transaction>> serializer);

	std::vector<std::shared_ptr<Transaction>> GetTransactions(TransactionType type);
	void WriteTransaction(std::shared_ptr<Transaction> transaction);
};