#pragma once

#include "BasicTransaction.hpp"

/**
 * \brief Transaction for deleting a user
 */
class DeleteTransaction : public BasicTransaction
{
public:
	/**
	 * \brief Initializes transaction with delete type
	 */
	explicit DeleteTransaction(const std::string &userName, UserType userType, float credits);
};