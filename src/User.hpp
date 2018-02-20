#pragma once

#include "UserType.hpp"
#include <string>

/**
* \brief Used to store users read by UserFile, and for in-memory state information
*/
class User
{
    std::string name;
    UserType type;
    double credits;

public:
	/**
     * \brief Initializes instance with specified information
     * \param name User name
     * \param type User account type
     * \param credits Amount of credits
     */
    User(std::string name, UserType type, double credits);

	/**
     * \brief Returns user's name
     * \return User name
     */
    const std::string &GetName() const;

	/**
     * \brief Returns user's account type
     * \return User account type
     */
    const UserType &GetType() const;

	/**
     * \brief Returns user's amount of credits
     * \return Amount of credits
     */
    const double &GetCredits() const;

	/**
     * \brief Sets the user's amount of credits
     * \param credits Amount of credits
     */
    void SetCredits(double credits);
};