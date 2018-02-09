#pragma once

#include "../Transactions/Transaction.hpp"
#include "../User.hpp"
#include <string>
#include <memory>

class IHandler
{
public:
	virtual ~IHandler() = default;

	virtual TransactionType GetType() = 0;
    virtual std::string GetName() = 0;
    virtual std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) = 0;
    virtual bool IsAllowed(std::shared_ptr<User> &user) = 0;
    virtual bool IsAvailable(std::shared_ptr<User> &user) = 0;
};