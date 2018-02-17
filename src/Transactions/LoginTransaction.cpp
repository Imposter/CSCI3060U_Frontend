#include "LoginTransaction.hpp"

LoginTransaction::LoginTransaction(const char *userName, UserType userType, float credits)
    : BasicTransaction(kTransactionType_Login, userName, userType, credits) {}