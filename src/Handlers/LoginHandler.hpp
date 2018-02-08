#pragma once

#include "IHandler.hpp"

class LoginHandler : public IHandler
{
public:
	TransactionType GetType() override;
	std::string GetName() override;
	Transaction Handle(std::shared_ptr<User> user) override;
	bool IsAllowed(std::shared_ptr<User> user) override;
	bool IsAvailable(std::shared_ptr<User> user) override;
};