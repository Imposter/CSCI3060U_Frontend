#pragma once

#include "BasicTransaction.hpp"

/**
 * \brief Transaction for creating a user
 */
class CreateTransaction : public BasicTransaction
{
public:
	/**
	 * \brief Initializes transaction with create type
	 */
	explicit CreateTransaction(const std::string &userName, UserType userType, double credits);
};