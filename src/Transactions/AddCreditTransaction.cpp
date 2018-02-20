#include "AddCreditTransaction.hpp"

AddCreditTransaction::AddCreditTransaction(const std::string &userName, UserType userType, double credits)
    : BasicTransaction(kTransactionType_AddCredit, userName, userType, credits) {}