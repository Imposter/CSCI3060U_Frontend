#include "LoginHandler.hpp"

TransactionType LoginHandler::GetType()
{
	return kTransactionType_Login;
}

std::string LoginHandler::GetName()
{
	return "login";
}

Transaction LoginHandler::Handle(std::shared_ptr<User> user)
{
	std::string input;
	std::cin >> input;

	

	// TODO: check length
	
}

bool LoginHandler::IsAllowed(std::shared_ptr<User> user)
{
	return true;
}

bool LoginHandler::IsAvailable(std::shared_ptr<User> user)
{
	// TODO: Implement

}