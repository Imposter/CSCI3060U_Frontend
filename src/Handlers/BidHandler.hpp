#pragma once

#include "IHandler.hpp"
#include "../TransactionFile.hpp"
#include "../UserFile.hpp"
#include "../ItemFile.hpp"
#include <iostream>

class BidHandler : public IHandler
{
    TransactionFile &transactionFile;
    UserFile &userFile;    
	ItemFile &itemFile;

public:
	BidHandler(TransactionFile &transactionFile, UserFile &userFile, ItemFile &itemFile);

	TransactionType GetType() override;
	std::string GetName() override;
	std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) override;
	bool IsAllowed(std::shared_ptr<User> &user) override;
	bool IsAvailable(std::shared_ptr<User> &user) override;
};