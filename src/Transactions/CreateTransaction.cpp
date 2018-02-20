#include "CreateTransaction.hpp"

CreateTransaction::CreateTransaction(const std::string &userName, UserType userType, double credits)
    : BasicTransaction(kTransactionType_Create, userName, userType, credits) {}