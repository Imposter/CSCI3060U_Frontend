#pragma once

#include "File.hpp"
#include "User.hpp"
#include <vector>
#include <memory>

/**
 * \brief Current users file used to get users by name
 */
class UserFile : public File
{
    std::vector<std::shared_ptr<User>> mUsers;

public:
	/**
	 * \brief Initializes file with specified file path
	 * \param fileName File path
	 */
	explicit UserFile(std::string fileName);

	/**
     * \brief Opens the user file and reads all the users into memory
     * \return Whether the file was successfully opened and read or not
     */
    bool Open();

	/**
	 * \brief Returns all of the user accounts that are currently present within the system
	 * \return All user accounts present in the user file
	 */
	std::vector<std::shared_ptr<User>> &GetUsers();

	/**
	 * \brief Returns a user in the file with the specified name
	 * \param userName Username to search
	 * \return User with specified name, if any
	 */
	std::shared_ptr<User> GetUserByName(std::string userName);
};