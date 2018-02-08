#include "LoginHandler.hpp"

TransactionType LoginHandler::GetType()
{
	return kTransactionType_Login;
}

std::string LoginHandler::GetName()
{
	return "login";
}

Transaction LoginHandler::Handle(const User &user)
{
	// TODO: Implement
}

bool LoginHandler::IsAllowed(const User &user)
{
	// TODO: Implement
}

bool LoginHandler::IsAvailable(const User &user)
{
	// TODO: Implement
}