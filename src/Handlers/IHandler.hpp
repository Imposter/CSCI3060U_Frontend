#pragma once

#include "../Transactions/Transaction.hpp"
#include "../User.hpp"
#include <string>

class IHandler
{
public:
	virtual ~IHandler() = default;

	virtual TransactionType GetType() = 0;
    virtual std::string GetName() = 0;
    
    // NOTE: This function prototype is subject to change once Transaction/User files are implemented
    // Hmm, should we return a std::shared_ptr<Transaction> here instead? 
    // Currently we copy the variable in memory when returning
    virtual Transaction Handle(const User &user) = 0;
                                                      
    virtual bool IsAllowed(const User &user) = 0;
    virtual bool IsAvailable(const User &user) = 0;
};