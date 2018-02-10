#pragma once

#include "BasicTransaction.hpp"

/**
 * \brief Transaction for adding credit
 */
class AddCreditTransaction : public BasicTransaction
{
public:
	/**
	 * \brief Initializes transaction with add credit type
	 */
	explicit AddCreditTransaction();
};