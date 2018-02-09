#include "Handlers/IHandler.hpp"
#include "Handlers/LoginHandler.hpp"

#include <iostream>
#include <vector>
#include <memory>

/**
 * \brief Program entrypoint implementing program logic and components
 * \param argc Argument count
 * \param argv Startup arguments provided
 * \return Exit code
 */
int main(int argc, char **argv)
{
	std::shared_ptr<User> user;

	// TODO: Take working directory from command line arguments, if none supplied then use current working directory ("./")

	// TODO: Load transaction, user account file, and available items file
	// ...
	
    std::vector<std::shared_ptr<IHandler>> handlers = {
		// TODO: We need to pass necessary files to handlers
		//std::make_shared<LoginHandler>(transactionFile, userFile) 
	};

	// Read input indefinitely
    std::string input;
	while (true) 
	{
        std::cout << "Enter a command: " << std::endl;
        getline(std::cin, input);

		if (input == "exit")
		{
			// TODO: Save files
			break;
		}

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