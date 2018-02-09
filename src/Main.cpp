#include "Handlers/IHandler.hpp"
#include "Handlers/LoginHandler.hpp"

#include <iostream>
#include <vector>
#include <memory>

int main(int argc, char **argv)
{
	std::shared_ptr<User> user;

	// TODO: Load transaction, user account files
	// ...
	
    std::vector<std::shared_ptr<IHandler>> handlers = { 
		std::make_shared<LoginHandler>() 
	};

    std::string input;
	while (true) 
	{
        std::cout << "Enter a command: " << std::endl;
        std::getline(std::cin, input);

		for (auto handler : handlers) 
		{
			if (input == handler->GetName())
			{
				// TODO: Check if command is allowed

				// TODO: Check if command is available

				auto transaction = handler->Handle(user);

				// TODO: Check if a transaction was returned
				
				// TODO: Use transaction (write to file)
			}
        }
    }

    return 0;
}