#pragma once

#include "BasicTransaction.hpp"

class DeleteTransaction : public BasicTransaction
{
public:
	explicit DeleteTransaction();
};