#pragma once

#include "IHandler.hpp"
#include "../TransactionFile.hpp"
#include "../ItemFile.hpp"

/**
* \brief Handles console input from user for the advertise command
*/
class AdvertiseHandler : public IHandler
{
	TransactionFile &mTransactionFile;
	ItemFile &mItemFile;

public:
	/**
	* \brief Initializes advertise handler with transactions and item file
	* \param transactionFile Daily transactions file
	* \param itemFile Available items file
	*/
	AdvertiseHandler(TransactionFile &transactionFile, ItemFile &itemFile);

	/**
	* \brief Returns advertise transaction type
	* \return Advertise transaction type
	*/
	TransactionType GetType() override;

	/**
	* \brief Returns advertise command name
	* \return Advertise command name
	*/
	std::string GetName() override;

	/**
	* \brief Handles advertise command for user
	* \param user User to handle advertise command for
	* \return AdvertiseTransaction if handling was successful
	*/
	std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) override;

	/**
	* \brief Returns if the advertise command is available for the user
	* \param user User to check against
	* \return Advertise command available for user
	*/
	bool IsAvailable(std::shared_ptr<User> &user) override;
};