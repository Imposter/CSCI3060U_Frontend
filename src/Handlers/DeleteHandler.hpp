#pragma once

#include "IHandler.hpp"
#include "../TransactionFile.hpp"
#include "../UserFile.hpp"

/**
 * \brief Handles console input from user for the delete command
 */
class DeleteHandler : public IHandler
{
	TransactionFile &transactionFile;
	UserFile &userFile;

public:
	/**
	 * \brief Initializes delete handler with transactions and user account file
	 * \param transactionFile Daily transactions file
	 * \param userFile User accounts file
	 */
	DeleteHandler(TransactionFile &transactionFile, UserFile &userFile);

	/**
	 * \brief Returns delete transaction type
	 * \return Delete transaction type
	 */
	TransactionType GetType() override;

	/**
	 * \brief Returns delete command name
	 * \return Delete command name
	 */
	std::string GetName() override;

	/**
	 * \brief Handles delete command for user
	 * \param user User to handle delete command for
	 * \return DeleteTransaction if handling was successful
	 */
	std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) override;

	/**
	 * \brief Returns if user is allowed to use the delete command
	 * \param user User to check against
	 * \return Delete command allowed for user
	 */
	bool IsAllowed(std::shared_ptr<User> &user) override;

	/**
	 * \brief Returns if the delete command is available for the user
	 * \param user User to check against
	 * \return Delete command available for user
	 */
	bool IsAvailable(std::shared_ptr<User> &user) override;
};