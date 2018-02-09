#pragma once

#include <string>

class Item
{
    std::string name;
    std::string sellerUserName;
    std::string bidderUserName;
    int daysToAuction;
    double currentBid;

public:
    Item(std::string name, std::string seller, std::string bidder, int daysToAuction, double currentBid);
    
    const std::string &GetName() const;
    const std::string &GetSellerName() const;
    const std::string &GetBidderName() const;
    const int &GetDaysToAuction() const;
    const int &GetCurrentBid() const;

    void SetBidderName(std::string bidder);
    void SetBid(double bid);
};