#include "LogoutTransaction.hpp"

LogoutTransaction::LogoutTransaction(const std::string &userName, UserType userType, float credits)
    : BasicTransaction(kTransactionType_Logout, userName, userType, credits) {}