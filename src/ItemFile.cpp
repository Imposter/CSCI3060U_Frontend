#include "ItemFile.hpp"
#include "Utility/String.hpp"
#include <sstream>

ItemFile::ItemFile(std::string fileName)
    : File(fileName) {}

bool ItemFile::Open()
{
    if (!File::Open())
        return false;

	// Read and parse items
	auto lines = ReadLines();
	for (auto line : lines)
	{
		std::stringstream stream(line);

		std::string itemName;
		std::string sellerUserName;
		std::string buyerUserName;
		int daysToAuction;
		double currentBid;

		stream >> itemName;
		stream >> sellerUserName;
		stream >> buyerUserName;
		stream >> daysToAuction;
		stream >> currentBid;

		// End of file user
		if (itemName == "END")
			break;

		items.push_back(std::make_shared<Item>(itemName, sellerUserName, buyerUserName, daysToAuction, currentBid));
	}
    
    return true;
}

std::vector<std::shared_ptr<Item>> &ItemFile::GetItems()
{
	return items;
}

std::shared_ptr<Item> ItemFile::GetItemByUserAndName(std::string userName, std::string itemName)
{
    std::shared_ptr<Item> result;
    
    // Find item by name
    for (auto item : items) 
    {
		// Perform a case insensitive check against item name to guarantee uniqueness
        if (String::Equals(item->GetSellerName(), userName, true) && String::Equals(item->GetName(), itemName, true))
        {
            result = item;
            break;
        }
    }

    return result;
}
