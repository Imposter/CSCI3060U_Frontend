#pragma once

#include <string>

/**
 * \brief User account type, used to determine privileges
 */
enum UserType
{
	/**
     * \brief Users of this type can only bid on items, and are non-privileged
     */
    kUserType_Buy,

	/**
     * \brief Users of this type can only advertise items, and are non-privileged
     */
    kUserType_Sell,

	/**
     * \brief Users of this type can bid on, and advertise items. They are semi-privileged
     */
    kUserType_Full,

	/**
     * \brief Users of this type can bid, advertise, create, delete, refund and add credit to users. They are fully-privileged
     */
    kUserType_Admin
};


/**
 * \brief Converts a specified user type to its string representation
 * \param type User type
 * \return User type in string representation
 */
std::string GetUserTypeString(UserType type);