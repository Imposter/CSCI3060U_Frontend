#include "ItemFile.hpp"

ItemFile::ItemFile(std::string fileName)
    : File(fileName) {}

bool ItemFile::Open()
{
    if (!File::Open())
        return false;

    // TODO: Read all items to vec.

    
    return true;
}

std::shared_ptr<Item> ItemFile::GetItemByName(std::string itemName)
{
    std::shared_ptr<Item> result;
    
    // Find item by name
    for (auto item : items) 
    {
        if (item->GetName() == itemName)
        {
            result = item;
            break;
        }
    }

    return result;
}