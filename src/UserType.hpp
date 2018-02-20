#pragma once

#include <string>

/**
 * \brief User account type, used to determine privileges
 */
enum UserType
{
	/**
	 * \brief Signifies an invalid user type
	 */
	kUserType_None = -1,

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

/**
* \brief Converts a specified user type to its long string representation
* \param type User type
* \return User type in long string representation
*/
std::string GetUserTypeLongString(UserType type);

/**
* \brief Converts a specified user type string to its integer representation
* \param type User type in short form
* \return User type in integer representation
*/
UserType GetUserTypeFromString(std::string &type);

/**
* \brief Converts a user type from string form to its integer representation
* \param type User type in long form
* \return User type in integer representation
*/
UserType GetUserTypeFromLongString(std::string &type);