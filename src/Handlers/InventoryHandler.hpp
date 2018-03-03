#pragma once

#include "IHandler.hpp"
#include "../TransactionFile.hpp"
#include "../ItemFile.hpp"

/**
* \brief Handles console input from user for the inventory command
*/
class InventoryHandler : public IHandler
{
	TransactionFile &mTransactionFile;
	ItemFile &mItemFile;

public:
	/**
	* \brief Initializes inventory handler with transaction and available items files
	* \param transactionFile Transaction file
	* \param itemFile Available items file
	*/
	explicit InventoryHandler(TransactionFile &transactionFile, ItemFile &itemFile);

	/**
	* \brief Returns inventory transaction type
	* \return No transaction type
	*/
	TransactionType GetType() override;

	/**
	* \brief Returns inventory command name
	* \return Inventory command name
	*/
	std::string GetName() override;

	/**
	* \brief Handles inventory command for user
	* \param user User to handle inventory command for
	* \return No transactions are returned
	*/
	std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) override;

	/**
	* \brief Returns if the inventory command is available for the user
	* \param user User to check against
	* \return Inventory command available for user
	*/
	bool IsAvailable(std::shared_ptr<User> &user) override;
};