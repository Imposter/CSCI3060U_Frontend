#pragma once

#include "IHandler.hpp"
#include "../TransactionFile.hpp"
#include "../UserFile.hpp"

/**
 * \brief Handles console input from user for the create command
 */
class CreateHandler : public IHandler
{
	TransactionFile &transactionFile;
	UserFile &userFile;

public:
	/**
	 * \brief Initializes create handler with transactions and user account file
	 * \param transactionFile Daily transactions file
	 * \param userFile User accounts file
	 */
	CreateHandler(TransactionFile &transactionFile, UserFile &userFile);

	/**
	 * \brief Returns create transaction type
	 * \return Create transaction type
	 */
	TransactionType GetType() override;

	/**
	 * \brief Returns create command name
	 * \return Create command name
	 */
	std::string GetName() override;

	/**
	 * \brief Handles create command for user
	 * \param user User to handle create command for
	 * \return CreateTransaction if handling was successful
	 */
	std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) override;

	/**
	 * \brief Returns if user is allowed to use the create command
	 * \param user User to check against
	 * \return Create command allowed for user
	 */
	bool IsAllowed(std::shared_ptr<User> &user) override;

	/**
	 * \brief Returns if the create command is available for the user
	 * \param user User to check against
	 * \return Create command available for user
	 */
	bool IsAvailable(std::shared_ptr<User> &user) override;
};