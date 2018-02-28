#include "AdvertiseHandler.hpp"
#include "../Config.hpp"
#include "../Transactions/AdvertiseTransaction.hpp"
#include "../Utility/String.hpp"
#include <iostream>

AdvertiseHandler::AdvertiseHandler(TransactionFile &transactionFile, ItemFile &itemFile)
	: mTransactionFile(transactionFile), mItemFile(itemFile) {}

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
		std::cerr << "ERROR: Item name is too long" << std::endl;
		return NULL;
	}

	// Check if item name is unique for seller
	const auto previousItem = mItemFile.GetItemByUserAndName(user->GetName(), itemName);
	if (previousItem)
	{
		std::cerr << "ERROR: Item already exists" << std::endl;
		return NULL;
	}

	// TODO: Document test to check for uniqueness in item name

	// Check if a similar transaction has already been posted
	for (const auto &t : mTransactionFile.GetTransactions(kTransactionType_Advertise))
	{
		// Perform case insensitive comparison to guarantee uniqueness
		const auto transaction = PointerCast::Reinterpret<AdvertiseTransaction>(t);
		if (transaction->GetSellerUserName() == user->GetName() && String::Equals(transaction->GetItemName(), itemName, true))
		{
			std::cerr << "ERROR: Item already exists" << std::endl;
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

	auto numPrice = strtod(itemPrice.c_str(), NULL);
	if (numPrice > ITEM_PRICE_MAX)
	{
		std::cerr << "ERROR: Price exceeds limit of " << ITEM_PRICE_MAX << std::endl;
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

	auto numAuctionDays = strtol(itemAuctionDays.c_str(), NULL, 10);
	if (numAuctionDays > ITEM_AUCTION_MAX)
	{
		std::cerr << "ERROR: Amount of days to auction exceeds limit of " << ITEM_AUCTION_MAX << std::endl;
		return NULL;
	}

	// Notify user that the item was advertised
	std::cout << "Posted advertisement " << itemName << " for $" << String::Format("%.2f", numPrice) << " active for " << numAuctionDays << " days" << std::endl;

	// Create item transaction
	return std::make_shared<AdvertiseTransaction>(itemName, user->GetName(), numAuctionDays, numPrice);
}

bool AdvertiseHandler::IsAvailable(std::shared_ptr<User> &user)
{
	return user != NULL && user->GetType() != kUserType_Buy;
}