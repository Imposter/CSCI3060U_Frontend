#include "Item.hpp"

Item::Item(std::string name, std::string seller, std::string bidder, int daysToAuction, double currentBid)
    : mName(name), mSellerUserName(seller), mBidderUserName(bidder), mDaysToAuction(daysToAuction), mCurrentBid(currentBid) {}

const std::string &Item::GetName() const
{
    return mName;
}

const std::string &Item::GetSellerName() const
{
    return mSellerUserName;
}

const std::string &Item::GetBidderName() const
{
    return mBidderUserName;
}

const int &Item::GetDaysToAuction() const
{
    return mDaysToAuction;
}

const double &Item::GetCurrentBid() const
{
    return mCurrentBid;
}

void Item::SetBidderName(std::string bidder)
{
    mBidderUserName = bidder;
}

void Item::SetBid(double bid)
{
    mCurrentBid = bid;
}