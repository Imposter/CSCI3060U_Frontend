#pragma once

#include "IHandler.hpp"
#include "../TransactionFile.hpp"
#include "../UserFile.hpp"
#include "../ItemFile.hpp"

/**
 * \brief Handles console input from user for the bid command
 */
class BidHandler : public IHandler
{
    TransactionFile &transactionFile;
    UserFile &userFile;    
	ItemFile &itemFile;

public:
	/**
	 * \brief Initializes bid handler with transactions, user account and item file
	 * \param transactionFile Daily transactions file
	 * \param userFile User accounts file
	 * \param itemFile Available items file
	 */
	BidHandler(TransactionFile &transactionFile, UserFile &userFile, ItemFile &itemFile);

	/**
	 * \brief Returns bid transaction type
	 * \return Bid transaction type
	 */
	TransactionType GetType() override;

	/**
	 * \brief Returns bid command name
	 * \return Bid command name
	 */
	std::string GetName() override;

	/**
	 * \brief Handles bid command for user
	 * \param user User to handle bid command for
	 * \return BidTransaction if handling was successful
	 */
	std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) override;

	/**
	 * \brief Returns if the bid command is available for the user
	 * \param user User to check against
	 * \return Bid command available for user
	 */
	bool IsAvailable(std::shared_ptr<User> &user) override;
};