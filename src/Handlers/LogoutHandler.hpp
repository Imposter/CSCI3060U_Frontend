#pragma once

#include "IHandler.hpp"
#include "../TransactionFile.hpp"
#include <iostream>

class LogoutHandler : public IHandler
{
	TransactionFile &transactionFile;

public:
	LogoutHandler(TransactionFile &transactionFile);

	TransactionType GetType() override;
	std::string GetName() override;
	std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) override;
	bool IsAllowed(std::shared_ptr<User> &user) override;
	bool IsAvailable(std::shared_ptr<User> &user) override;
};