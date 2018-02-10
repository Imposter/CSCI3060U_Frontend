#pragma once

#include "IHandler.hpp"
#include "../TransactionFile.hpp"

/**
 * \brief Handles console input from user for the logout command
 */
class LogoutHandler : public IHandler
{
	TransactionFile &transactionFile;

public:
	/**
	 * \brief Initializes logout handler with transactions file
	 * \param transactionFile Daily transactions file
	 */
	explicit LogoutHandler(TransactionFile &transactionFile);

	/**
	 * \brief Returns logout transaction type
	 * \return Logout transaction type
	 */
	TransactionType GetType() override;

	/**
	 * \brief Returns logout command name
	 * \return Logout command name
	 */
	std::string GetName() override;

	/**
	 * \brief Handles logout command for user
	 * \param user User to handle logout command for
	 * \return LogoutTransaction if handling was successful
	 */
	std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) override;

	/**
	 * \brief Returns if user is allowed to use the logout command
	 * \param user User to check against
	 * \return Logout command allowed for user
	 */
	bool IsAllowed(std::shared_ptr<User> &user) override;

	/**
	 * \brief Returns if the logout command is available for the user
	 * \param user User to check against
	 * \return Logout command available for user
	 */
	bool IsAvailable(std::shared_ptr<User> &user) override;
};