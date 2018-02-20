#include "LoginTransaction.hpp"

LoginTransaction::LoginTransaction(const std::string &userName, UserType userType, double credits)
    : BasicTransaction(kTransactionType_Login, userName, userType, credits) {}