#include "InventoryHandler.hpp"
#include "../Transactions/BidTransaction.hpp"
#include "../Utility/String.hpp"
#include <iostream>
#include "../Config.hpp"

InventoryHandler::InventoryHandler(TransactionFile &transactionFile, ItemFile &itemFile) 
	: mTransactionFile(transactionFile), mItemFile(itemFile) {}

TransactionType InventoryHandler::GetType()
{
	return kTransactionType_None;
}

std::string InventoryHandler::GetName()
{
	return "inventory";
}

std::shared_ptr<Transaction> InventoryHandler::Handle(std::shared_ptr<User> &user)
{
	// Get all available items
	auto items = mItemFile.GetItems();
	if (items.empty())
	{
		std::cout << "There are currently no items in the inventory" << std::endl;
		return NULL;
	}

	// Get all bid transactions
	auto transactions = mTransactionFile.GetTransactions(kTransactionType_Bid);

	std::cout << String::PadRight("Item Name", ' ', ITEM_NAME_LENGTH) << "| "
		<< String::PadRight("Seller", ' ', USERNAME_LENGTH) << "| "
		<< String::PadRight("Bidder", ' ', USERNAME_LENGTH) << "| "
		<< String::PadRight("Bid", ' ', ITEM_PRICE_LENGTH) << " | "
		<< String::PadRight("Days Left", ' ', ITEM_AUCTION_LENGTH)
		<< std::endl;

	for (const auto &item : items)
	{
		// Get latest bid for item
		auto bidder = item->GetBidderName();
		auto bid = item->GetCurrentBid();

		for (const auto &t : transactions)
		{
			// Cast to bid transaction
			const auto transaction = PointerCast::Reinterpret<BidTransaction>(t);
			if (transaction->GetItemName() == item->GetName() && transaction->GetSellerUserName() == item->GetSellerName())
			{
				bidder = transaction->GetBuyerUserName();
				bid = transaction->GetNewBid();
			}
		}

		// Print item information
		std::cout << String::PadRight(item->GetName(), ' ', ITEM_NAME_LENGTH) << "| "
			<< String::PadRight(item->GetSellerName(), ' ', USERNAME_LENGTH) << "| "
			<< String::PadRight(bidder, ' ', USERNAME_LENGTH) << "| "
			<< String::PadRight(String::Format("%.2f", bid), ' ', ITEM_PRICE_LENGTH) << " | "
			<< String::PadRight(std::to_string(item->GetDaysToAuction()), ' ', ITEM_AUCTION_LENGTH)
			<< std::endl;
	}

	return NULL;
}

bool InventoryHandler::IsAvailable(std::shared_ptr<User> &user)
{
	// User must be logged in
	return user != NULL;
}