#pragma once

#include "IHandler.hpp"
#include "../TransactionFile.hpp"
#include "../UserFile.hpp"

/**
 * \brief Handles console input from user for the refund command
 */
class RefundHandler : public IHandler
{
    TransactionFile &transactionFile;
    UserFile &userFile;

public:
	/**
	 * \brief Initializes refund handler with transactions and user account file
	 * \param transactionFile Daily transactions file
	 * \param userFile User accounts file
	 */
	RefundHandler(TransactionFile &transactionFile, UserFile &userFile);

	/**
	 * \brief Returns refund transaction type
	 * \return Refund transaction type
	 */
	TransactionType GetType() override;

	/**
	 * \brief Returns refund command name
	 * \return Refund command name
	 */
	std::string GetName() override;

	/**
	 * \brief Handles refund command for user
	 * \param user User to handle refund command for
	 * \return RefundTransaction if handling was successful
	 */
	std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) override;

	/**
	 * \brief Returns if user is allowed to use the refund command
	 * \param user User to check against
	 * \return Refund command allowed for user
	 */
	bool IsAllowed(std::shared_ptr<User> &user) override;

	/**
	 * \brief Returns if the refund command is available for the user
	 * \param user User to check against
	 * \return Refund command available for user
	 */
	bool IsAvailable(std::shared_ptr<User> &user) override;
};