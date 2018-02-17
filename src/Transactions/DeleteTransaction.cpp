#include "DeleteTransaction.hpp"

DeleteTransaction::DeleteTransaction(const char *userName, UserType userType, float credits)
    : BasicTransaction(kTransactionType_Delete, userName, userType, credits) {}