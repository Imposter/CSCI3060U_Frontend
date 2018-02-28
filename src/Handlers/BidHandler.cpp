#include "BidHandler.hpp"
#include "../Transactions/BidTransaction.hpp"
#include "../Config.hpp"
#include "../Utility/String.hpp"
#include <iostream>

BidHandler::BidHandler(TransactionFile &transactionFile, UserFile &userFile, ItemFile &itemFile)
	: transactionFile(transactionFile), userFile(userFile), itemFile(itemFile) {}

TransactionType BidHandler::GetType()
{
	return kTransactionType_Bid;
}

std::string BidHandler::GetName()
{
	return "bid";
}

std::shared_ptr<Transaction> BidHandler::Handle(std::shared_ptr<User> &user)
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

	// Get item name
	std::string sellerName;
	std::cout << "Enter seller name: ";
	getline(std::cin, sellerName);

	// Check if the item name refers to an existing item
	auto item = itemFile.GetItemByUserAndName(sellerName, itemName);
	if (!item)
	{
		std::cerr << "ERROR: Item does not exist" << std::endl;
		return NULL;
	}

	// Check if the seller is an existing user
	const auto sellerUser = userFile.GetUserByName(sellerName);
	if (!sellerUser)
	{
		std::cerr << "ERROR: Cannot bid on this item" << std::endl;
		return NULL;
	}

	// Check if you were the last bidder
	if (String::Equals(sellerName, user->GetName(), true))
	{
		std::cerr << "ERROR: You already have the highest bid" << std::endl;
		return NULL;
	}

	// Get bid
	std::string newBid;
	std::cout << "Enter new bid: ";
	getline(std::cin, newBid);

	// Check if number
	if (!String::IsNumber(newBid))
	{
		std::cerr << "ERROR: Invalid bid" << std::endl;
		return NULL;
	}

	const auto numBid = strtod(newBid.c_str(), NULL);
	if (numBid > ITEM_PRICE_MAX)
	{
		std::cerr << "ERROR: Bid exceeds limit of " << ITEM_PRICE_MAX << std::endl;
		return NULL;
	}

	// Check if new bid is greater than last bid
	if (numBid <= item->GetCurrentBid())
	{
		std::cerr << "ERROR: Invalid bid (must be greater than previous bid)" << std::endl;
		return NULL;
	}

	// Check if new bid exceeds previous bid by at least 5% if user is not an admin
	if (user->GetType() != kUserType_Admin && item->GetCurrentBid() / numBid >= 0.95)
	{
		std::cerr << "ERROR: Invalid bid (must be greater than previous bid by at least 5%)" << std::endl;
		return NULL;
	}

	// Check if the user can afford to make the bid
	if (user->GetCredits() - numBid < 0)
	{
		std::cerr << "ERROR: You do not have enough credits to bid on this item" << std::endl;
		return NULL;
	}

	// Apply changes to item
	item->SetBidderName(user->GetName());
	item->SetBid(numBid);

	// Remove amount of credits from the user (they will be returned to the user on the next day)
	user->SetCredits(user->GetCredits() - numBid);

	// Notify user that the item was bid on
	std::cout << "Bid on " << itemName << " by " << sellerName << " with $" << String::Format("%.2f", numBid) << std::endl;

	// Create transaction
	return std::make_shared<BidTransaction>(item->GetName(), item->GetSellerName(), item->GetBidderName(), item->GetCurrentBid());
}

bool BidHandler::IsAvailable(std::shared_ptr<User> &user)
{
	return user != NULL && user->GetType() != kUserType_Sell;
}