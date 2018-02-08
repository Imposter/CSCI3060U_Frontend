#pragma once

#include "IHandler.hpp"

class LoginHandler : public IHandler
{
public:
	TransactionType GetType() override;
	std::string GetName() override;
	Transaction Handle(const User &user) override;
	bool IsAllowed(const User &user) override;
	bool IsAvailable(const User &user) override;
};