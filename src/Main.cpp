#include "TransactionFile.hpp"
#include "UserFile.hpp"
#include "ItemFile.hpp"

#include "Transactions/BasicTransaction.hpp"
#include "Transactions/AdvertiseTransaction.hpp"
#include "Transactions/BidTransaction.hpp"
#include "Transactions/RefundTransaction.hpp"

#include "Handlers/IHandler.hpp"
#include "Handlers/LoginHandler.hpp"
#include "Handlers/LogoutHandler.hpp"
#include "Handlers/CreateHandler.hpp"
#include "Handlers/DeleteHandler.hpp"
#include "Handlers/AdvertiseHandler.hpp"
#include "Handlers/BidHandler.hpp"

#include <iostream>
#include <fstream>
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
	// Get files
	std::string userFilePath = "data/current_users.txt";
	std::string itemFilePath = "data/available_items.txt";
	std::string transactionFilePath = "data/transactions.txt";

	// Override default files with ones provided
	if (argc >= 4)
	{
		userFilePath = argv[1];
		itemFilePath = argv[2];
		transactionFilePath = argv[3];
	}

	// Create transaction file if it does not exist
	{
		std::fstream transactionFile;
		transactionFile.open(transactionFilePath, std::ios::in);
		if (!transactionFile.is_open())
		{
			transactionFile.open(transactionFilePath, std::ios::out);
			transactionFile.close();
		}
	}

	// Load files
	UserFile userFile(userFilePath);
	ItemFile itemFile(itemFilePath);
	TransactionFile transactionFile(transactionFilePath);

	if (!userFile.Open())
	{
		std::cerr << "Unable to open user file!" << std::endl;
		return EXIT_FAILURE;
	}

	if (!itemFile.Open())
	{
		std::cerr << "Unable to open available items file!" << std::endl;
		return EXIT_FAILURE;
	}

	// Open in append mode
	if (!transactionFile.Open(true))
	{
		std::cerr << "Unable to open transactions file!" << std::endl;
		return EXIT_FAILURE;
	}

	// Create serializers
	transactionFile.AddSerializer<BasicTransaction>(kTransactionType_Login, std::make_shared<BasicTransaction::Serializer>());
	transactionFile.AddSerializer<BasicTransaction>(kTransactionType_Logout, std::make_shared<BasicTransaction::Serializer>());
	transactionFile.AddSerializer<BasicTransaction>(kTransactionType_Create, std::make_shared<BasicTransaction::Serializer>());
	transactionFile.AddSerializer<BasicTransaction>(kTransactionType_Delete, std::make_shared<BasicTransaction::Serializer>());
	transactionFile.AddSerializer<AdvertiseTransaction>(kTransactionType_Advertise, std::make_shared<AdvertiseTransaction::Serializer>());
	transactionFile.AddSerializer<BidTransaction>(kTransactionType_Bid, std::make_shared<BidTransaction::Serializer>());
	transactionFile.AddSerializer<RefundTransaction>(kTransactionType_Refund, std::make_shared<RefundTransaction::Serializer>());
	transactionFile.AddSerializer<BasicTransaction>(kTransactionType_AddCredit, std::make_shared<BasicTransaction::Serializer>());

	// Create handlers
	std::vector<std::shared_ptr<IHandler>> handlers = {
		std::make_shared<LoginHandler>(transactionFile, userFile),
		std::make_shared<LogoutHandler>(),
		std::make_shared<CreateHandler>(transactionFile, userFile),
		std::make_shared<DeleteHandler>(transactionFile, userFile),
		std::make_shared<AdvertiseHandler>(transactionFile, itemFile),
		std::make_shared<BidHandler>(transactionFile, userFile, itemFile),
	};

	// Pointer for current user
	std::shared_ptr<User> user;

	// Read input indefinitely
    std::string input;
	while (true) 
	{
        std::cout << "Auction> ";
        getline(std::cin, input);

		// Ignore empty lines
		if (input.empty())
			continue;

		if (input == "?")
		{
			// Output all the available commands
			std::cout << "Available commands:" << std::endl;
			for (const auto &handler : handlers)
				if (handler->IsAvailable(user))
					std::cout << "> " << handler->GetName() << std::endl;
			if (!user)
				std::cout << "> exit" << std::endl;

			// We've handled the command, so wait for another one
			continue;
		}

		// Only be available once a user has logged out, or hasn't logged in
		if (!user && input == "exit")
		{
			// Save and close files
			transactionFile.Close();
			itemFile.Close();
			userFile.Close();

			break;
		}

		auto commandFound = false;
		for (const auto &handler : handlers) 
		{
			if (input == handler->GetName())
			{
				// Set as handled
				commandFound = true;

				// Check if command is available
				if (!handler->IsAvailable(user))
				{
					std::cerr << "ERROR: Access denied" << std::endl;
					break;
				}

				// Handle request
				const auto transaction = handler->Handle(user);

				// Check if a transaction was returned
				if (transaction)
				{
					// Write transaction to daily transactions file
					transactionFile.WriteTransaction(transaction);
				}
			}
        }

		if (!commandFound)
			std::cerr << "Unknown command" << std::endl;
    }

    return 0;
}