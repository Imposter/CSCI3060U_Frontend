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
	std::cout << "Enter in an existing username: ";
	std::cin >> input;

	// TODO: check if account exists
	// TODO: check length ???
	
}

bool LoginHandler::IsAllowed(std::shared_ptr<User> user)
{
	// Login is authorized for everyone
	return true;
}

bool LoginHandler::IsAvailable(std::shared_ptr<User> user)
{
	// Login is only available if user is unknown
	return (user == NULL);
}