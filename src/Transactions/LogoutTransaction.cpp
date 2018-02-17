#include "LogoutTransaction.hpp"

LogoutTransaction::LogoutTransaction(const char *userName, UserType userType, float credits)
    : BasicTransaction(kTransactionType_Logout, userName, userType, credits) {}