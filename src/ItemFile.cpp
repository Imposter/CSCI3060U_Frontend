#include "ItemFile.hpp"
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