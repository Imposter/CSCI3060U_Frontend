#include "CreateTransaction.hpp"

CreateTransaction::CreateTransaction(const std::string &userName, UserType userType, float credits)
    : BasicTransaction(kTransactionType_Create, userName, userType, credits) {}