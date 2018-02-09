#pragma once

#include "File.hpp"
#include "Item.hpp"
#include <vector>
#include <memory>

class ItemFile : public File 
{
    std::vector<std::shared_ptr<Item>> items;

public:
    ItemFile(std::string fileName);
    bool Open();

	std::shared_ptr<Item> GetItemByName(std::string itemName);
};