#pragma once

#include "IHandler.hpp"
#include "../TransactionFile.hpp"
#include "../UserFile.hpp"
#include "../ItemFile.hpp"

/**
* \brief Handles console input from user for the add credit command
*/
class AddCreditHandler : public IHandler
{
    TransactionFile &mTransactionFile;
    UserFile &mUserFile;

public:
	/**
	* \brief Initializes add credit handler with transactions, user account and item file
	* \param transactionFile Daily transactions file
	* \param userFile User accounts file
	* \param itemFile Available items file
	*/
	AddCreditHandler(TransactionFile &transactionFile, UserFile &userFile);

	/**
	* \brief Returns add credit transaction type
	* \return Add credit transaction type
	*/
	TransactionType GetType() override;

	/**
	* \brief Returns add credit command name
	* \return Add credit command name
	*/
	std::string GetName() override;

	/**
	* \brief Handles add credit command for user
	* \param user User to handle add credit command for
	* \return AddCreditTransaction if handling was successful
	*/
	std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) override;

	/**
	* \brief Returns if the add credit command is available for the user
	* \param user User to check against
	* \return Add credit command available for user
	*/
	bool IsAvailable(std::shared_ptr<User> &user) override;
};