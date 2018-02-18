#include "AddCreditTransaction.hpp"

AddCreditTransaction::AddCreditTransaction(const std::string &userName, UserType userType, float credits)
    : BasicTransaction(kTransactionType_AddCredit, userName, userType, credits) {}