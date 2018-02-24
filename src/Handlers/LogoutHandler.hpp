#pragma once

#include "IHandler.hpp"
#include "../TransactionFile.hpp"

/**
 * \brief Handles console input from user for the logout command
 */
class LogoutHandler : public IHandler
{
public:
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
	 * \brief Returns if the logout command is available for the user
	 * \param user User to check against
	 * \return Logout command available for user
	 */
	bool IsAvailable(std::shared_ptr<User> &user) override;
};