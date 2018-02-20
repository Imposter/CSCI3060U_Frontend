#pragma once

#include "BasicTransaction.hpp"

/**
 * \brief Transaction for a user logging out
 */
class LogoutTransaction : public BasicTransaction
{
public:
	/**
	 * \brief Initializes transaction with logout type
	 */
	explicit LogoutTransaction(const std::string &userName, UserType userType, double credits);
};