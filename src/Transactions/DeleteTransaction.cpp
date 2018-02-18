#include "DeleteTransaction.hpp"

DeleteTransaction::DeleteTransaction(const std::string &userName, UserType userType, double credits)
    : BasicTransaction(kTransactionType_Delete, userName, userType, credits) {}