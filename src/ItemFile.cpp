#include "ItemFile.hpp"
#include "Config.hpp"
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
	for (const auto &line : lines)
	{
		// End of file item
		if (line == "END")
			break;

		std::stringstream stream(line);

		std::string itemName;
		std::string sellerUserName;
		std::string buyerUserName;
		int daysToAuction;
		double currentBid;

		// Read item name
		itemName.resize(ITEM_NAME_LENGTH);
		stream.read(const_cast<char *>(itemName.c_str()), ITEM_NAME_LENGTH);
		itemName = String::TrimRight(itemName);
		stream.ignore();

		// Read seller name
		sellerUserName.resize(USERNAME_LENGTH);
		stream.read(const_cast<char *>(sellerUserName.c_str()), USERNAME_LENGTH);
		sellerUserName = String::TrimRight(sellerUserName);
		stream.ignore();

		// Read buyer name
		buyerUserName.resize(USERNAME_LENGTH);
		stream.read(const_cast<char *>(buyerUserName.c_str()), USERNAME_LENGTH);
		buyerUserName = String::TrimRight(buyerUserName);
		stream.ignore();

		stream >> daysToAuction;
		stream >> currentBid;

		mItems.push_back(std::make_shared<Item>(itemName, sellerUserName, buyerUserName, daysToAuction, currentBid));
	}
    
    return true;
}

std::vector<std::shared_ptr<Item>> &ItemFile::GetItems()
{
	return mItems;
}

std::shared_ptr<Item> ItemFile::GetItemByUserAndName(std::string userName, std::string itemName)
{
    std::shared_ptr<Item> result;
    
    // Find item by name
    for (const auto &item : mItems) 
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
