#include "RefundHandler.hpp"
#include "../Transactions/RefundTransaction.hpp"
#include "../Config.hpp"
#include "../Utility/String.hpp"
#include <iostream>

RefundHandler::RefundHandler(TransactionFile &transactionFile, UserFile &userFile)
	: mTransactionFile(transactionFile), mUserFile(userFile) {}

TransactionType RefundHandler::GetType()
{
	return kTransactionType_Refund;
}

std::string RefundHandler::GetName()
{
	return "refund";
}

std::shared_ptr<Transaction> RefundHandler::Handle(std::shared_ptr<User> &user)
{
	// Get buyer username
	std::string buyerName;
	std::cout << "Enter buyer name: ";
	getline(std::cin, buyerName);

	// Check if buyer account exists in the user file
	if (!mUserFile.GetUserByName(buyerName))
	{
		std::cerr << "ERROR: Buyer user does not exist" << std::endl;
		return NULL;
	}

	// Get seller username
	std::string sellerName;
	std::cout << "Enter seller name: ";
	getline(std::cin, sellerName);

	// Check if seller account exists in the user file
	if (!mUserFile.GetUserByName(sellerName))
	{
		std::cerr << "ERROR: Seller user does not exist" << std::endl;
		return NULL;
	}

	// Ask for amount of credits
	std::string credits;
	std::cout << "Enter credits to return: ";
	getline(std::cin, credits);

	// Check if number
	if (!String::IsNumber(credits))
	{
		std::cerr << "ERROR: Invalid credits" << std::endl;
		return NULL;
	}

	auto numCredits = strtod(credits.c_str(), NULL);
	if (numCredits > ITEM_PRICE_MAX)
	{
		std::cerr << "ERROR: Credits exceed limit of " << CREDITS_MAX << std::endl;
		return NULL;
	}

	// Prompt success
	std::cout << sellerName << " refunded " << buyerName << " $" << String::Format("%.2f", numCredits);

	return std::make_shared<RefundTransaction>(buyerName, sellerName, numCredits);
}

bool RefundHandler::IsAvailable(std::shared_ptr<User> &user)
{
	// Ensure the user is logged in and is an admin
	return user != NULL && user->GetType() == kUserType_Admin;
}