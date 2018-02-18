#include "LoginTransaction.hpp"

LoginTransaction::LoginTransaction(const std::string &userName, UserType userType, float credits)
    : BasicTransaction(kTransactionType_Login, userName, userType, credits) {}