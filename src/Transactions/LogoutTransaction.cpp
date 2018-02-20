#include "LogoutTransaction.hpp"

LogoutTransaction::LogoutTransaction(const std::string &userName, UserType userType, double credits)
    : BasicTransaction(kTransactionType_Logout, userName, userType, credits) {}