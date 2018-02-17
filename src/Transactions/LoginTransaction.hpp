#pragma once

#include "BasicTransaction.hpp"

/**
 * \brief Transaction for a user logging in
 */
class LoginTransaction : public BasicTransaction
{
public:
	/**
	 * \brief Initializes transaction with login type
	 */
	explicit LoginTransaction(const char *userName, UserType userType, float credits);
};