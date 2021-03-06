#pragma once

#include "IHandler.hpp"
#include "../TransactionFile.hpp"
#include "../UserFile.hpp"

/**
 * \brief Handles console input from user for the login command
 */
class LoginHandler : public IHandler
{
	TransactionFile &mTransactionFile;
	UserFile &mUserFile;

public:
	/**
	 * \brief Initializes login handler with transaction and user accounts files
	 * \param transactionFile Transaction file
	 * \param userFile User accounts file
	 */
	explicit LoginHandler(TransactionFile &transactionFile, UserFile &userFile);

	/**
	 * \brief Returns login transaction type
	 * \return Login transaction type
	 */
	TransactionType GetType() override;

	/**
	 * \brief Returns login command name
	 * \return Login command name
	 */
	std::string GetName() override;

	/**
	 * \brief Handles login command for user
	 * \param user User to handle login command for
	 * \return LoginTransaction if handling was successful
	 */
	std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) override;

	/**
	 * \brief Returns if the login command is available for the user
	 * \param user User to check against
	 * \return Login command available for user
	 */
	bool IsAvailable(std::shared_ptr<User> &user) override;
};