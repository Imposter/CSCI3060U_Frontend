#include "CreateTransaction.hpp"

CreateTransaction::CreateTransaction(const char *userName, UserType userType, float credits)
    : BasicTransaction(kTransactionType_Create, userName, userType, credits) {}