#pragma once

#include "../Transactions/Transaction.hpp"
#include "../User.hpp"
#include <string>
#include <memory>

/**
 * \brief Interface used to implement command input handlers for the main application
 */
class IHandler
{
public:
	/**
	 * \brief Default virtual destructor
	 */
	virtual ~IHandler() = default;

	/**
	 * \brief Identify the transaction type that handler is used for
	 * \return Handler's transaction type
	 */
	virtual TransactionType GetType() = 0;

	/**
     * \brief Identify the transaction command name that the handler is used for
     * \return Handler's command name
     */
    virtual std::string GetName() = 0;

	/**
     * \brief Handles the transaction for which the command was input
     * \param user User pointer reference for information regarding the currently logged in user, if any
     * \return Pointer to the successful transaction to write to the transaction file
     */
    virtual std::shared_ptr<Transaction> Handle(std::shared_ptr<User> &user) = 0;

	/**
     * \brief Used to test if the handler is available for the user in their current state
     * \param user User for which the handler will be used
     * \return Whether the handler is available or not
     */
    virtual bool IsAvailable(std::shared_ptr<User> &user) = 0;
};