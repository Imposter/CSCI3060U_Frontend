#include "DeleteTransaction.hpp"

DeleteTransaction::DeleteTransaction(const std::string &userName, UserType userType, float credits)
    : BasicTransaction(kTransactionType_Delete, userName, userType, credits) {}