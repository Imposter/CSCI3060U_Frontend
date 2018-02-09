#pragma once

#include "IHandler.hpp"
#include "../TransactionFile.hpp"
#include "../UserFile.hpp"

class LoginHandler : public IHandler
{
	TransactionFile &transactionFile;
	UserFile &userFile;

public:
	LoginHandler(TransactionFile &transactionFile, UserFile &userFile);

	TransactionType GetType() override;
	std::string GetName() override;
	std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) override;
	bool IsAllowed(std::shared_ptr<User> &user) override;
	bool IsAvailable(std::shared_ptr<User> &user) override;
};