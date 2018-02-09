#include "Item.hpp"

Item::Item(std::string name, std::string seller, std::string bidder, int daysToAuction, double currentBid)
    : name(name), sellerUserName(seller), bidderUserName(bidder), daysToAuction(daysToAuction), currentBid(currentBid) {}

const std::string &Item::GetName() const
{
    return name;
}

const std::string &Item::GetSellerName() const
{
    return sellerUserName;
}

const std::string &Item::GetBidderName() const
{
    return bidderUserName;
}

const int &Item::GetDaysToAuction() const
{
    return daysToAuction;
}

const int &Item::GetCurrentBid() const
{
    return currentBid;
}

void Item::SetBidderName(std::string bidder)
{
    bidderUserName = bidder;
}

void Item::SetBid(double bid)
{
    currentBid = bid;
}