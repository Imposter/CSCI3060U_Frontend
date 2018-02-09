#pragma once

#include "IHandler.hpp"
#include "../TransactionFile.hpp"
#include "../ItemFile.hpp"

class AdvertiseHandler : public IHandler
{
	TransactionFile &transactionFile;
	ItemFile &itemFile;

public:
	AdvertiseHandler(TransactionFile &transactionFile, ItemFile &itemFile);

	TransactionType GetType() override;
	std::string GetName() override;
	std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) override;
	bool IsAllowed(std::shared_ptr<User> &user) override;
	bool IsAvailable(std::shared_ptr<User> &user) override;
};