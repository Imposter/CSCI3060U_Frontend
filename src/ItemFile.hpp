#pragma once

#include "File.hpp"
#include "Item.hpp"
#include <vector>
#include <memory>

/**
 * \brief Available items file used to get currently available items for auction
 */
class ItemFile : public File 
{
    std::vector<std::shared_ptr<Item>> items;

public:
	/**
	 * \brief Initializes item file with file path
	 * \param fileName File path
	 */
	explicit ItemFile(std::string fileName);

	/**
     * \brief Opens file and reads the items to memory
     * \return Whether the file was succesfully opened and read or not
     */
    bool Open();

	/**
	 * \brief Returns all of the items that are currently available in the system
	 * \return All of the items that are present within the item file
	 */
	std::vector<std::shared_ptr<Item>> &GetItems();

	/**
	 * \brief Attempts to find an item by the specified name and creator
	 * \param userName User which created the item
	 * \param itemName Item name to search for
	 * \return Pointer to item found, if any
	 */
	std::shared_ptr<Item> GetItemByUserAndName(std::string userName, std::string itemName);
};