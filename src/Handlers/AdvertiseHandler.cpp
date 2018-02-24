#include "AdvertiseHandler.hpp"
#include "../Config.hpp"
#include "../Transactions/AdvertiseTransaction.hpp"
#include "../Utility/String.hpp"
#include <iostream>

AdvertiseHandler::AdvertiseHandler(TransactionFile &transactionFile, ItemFile &itemFile)
	: transactionFile(transactionFile), itemFile(itemFile) {}

TransactionType AdvertiseHandler::GetType()
{
	return kTransactionType_Advertise;
}

std::string AdvertiseHandler::GetName()
{
	return "advertise";
}

std::shared_ptr<Transaction> AdvertiseHandler::Handle(std::shared_ptr<User> &user)
{
	// Get item name
	std::string itemName;
	std::cout << "Enter item name: ";
	getline(std::cin, itemName);

	// Check item name length
	if (itemName.size() > ITEM_NAME_LENGTH)
	{
		std::cerr << "ERROR: Invalid item name (too long)" << std::endl;
		return NULL;
	}

	// Check if item name is unique for seller
	auto previousItem = itemFile.GetItemByUserAndName(user->GetName(), itemName);
	if (previousItem)
	{
		std::cerr << "ERROR: Invalid item name (already exists)" << std::endl;
		return NULL;
	}

	// TODO: Document test to check for uniqueness in item name

	// Check if a similar transaction has already been posted
	for (auto t : transactionFile.GetTransactions(kTransactionType_Advertise))
	{
		// Perform case insensitive comparison to guarantee uniqueness
		auto transaction = PointerCast::Reinterpret<AdvertiseTransaction>(t);
		if (transaction->GetSellerUserName() == user->GetName() && String::Equals(transaction->GetItemName(), itemName, true))
		{
			std::cerr << "ERROR: Invalid item name (already exists)" << std::endl;
			return NULL;
		}
	}

	// Get item price
	std::string itemPrice;
	std::cout << "Enter price: ";
	getline(std::cin, itemPrice);

	// Check if number
	if (!String::IsNumber(itemPrice))
	{
		std::cerr << "ERROR: Invalid price" << std::endl;
		return NULL;
	}

	auto numPrice = atof(itemPrice.c_str());
	if (numPrice > ITEM_PRICE_MAX)
	{
		std::cerr << "ERROR: Invalid price (exceeded limit)" << std::endl;
		return NULL;
	}

	// Ask for auction days
	std::string itemAuctionDays;
	std::cout << "Enter auction length (in days): ";
	getline(std::cin, itemAuctionDays);

	// Check if number
	if (!String::IsNumber(itemAuctionDays))
	{
		std::cerr << "ERROR: Invalid amount of days to auction" << std::endl;
		return NULL;
	}

	auto numAuctionDays = atoi(itemAuctionDays.c_str());
	if (numAuctionDays > ITEM_AUCTION_MAX)
	{
		std::cerr << "ERROR: Invalid amount of days to auction (exceeded limit)" << std::endl;
		return NULL;
	}

	// Create item transaction
	return std::make_shared<AdvertiseTransaction>(itemName, user->GetName(), numAuctionDays, numPrice);
}

bool AdvertiseHandler::IsAvailable(std::shared_ptr<User> &user)
{
	return user != NULL && user->GetType() != kUserType_Buy;
}