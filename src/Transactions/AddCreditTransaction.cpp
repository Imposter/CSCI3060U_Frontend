#include "AddCreditTransaction.hpp"

AddCreditTransaction::AddCreditTransaction(const char *userName, UserType userType, float credits)
    : BasicTransaction(kTransactionType_AddCredit, userName, userType, credits) {}