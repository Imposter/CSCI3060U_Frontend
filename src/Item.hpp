#pragma once

#include <string>

/**
 * \brief Used to store items read by ItemFile, and for in-memory state information
 */
class Item
{
    std::string mName;
    std::string mSellerUserName;
    std::string mBidderUserName;
    int mDaysToAuction;
    double mCurrentBid;

public:
	/**
     * \brief Initializes item with information provided
     * \param name Item name
     * \param seller Seller name
     * \param bidder Bidder name
     * \param daysToAuction Days left to auction
     * \param currentBid Current bid
     */
    Item(std::string name, std::string seller, std::string bidder, int daysToAuction, double currentBid);
    
	/**
     * \brief Returns item's name
     * \return Item name
     */
    const std::string &GetName() const;

	/**
     * \brief Returns seller's name
     * \return Seller name
     */
    const std::string &GetSellerName() const;

	/**
     * \brief Returns currently highest bidder's name
     * \return Currently highest bidder name
     */
    const std::string &GetBidderName() const;

	/**
     * \brief Returns days left to auction
     * \return Days left to auction
     */
    const int &GetDaysToAuction() const;

	/**
     * \brief Returns currently highest bidder's bid
     * \return Currently highest bid
     */
    const double &GetCurrentBid() const;

	/**
     * \brief Sets the currently highest bidder
     * \param bidder Highest bidder
     */
    void SetBidderName(std::string bidder);

	/**
     * \brief Sets the currently highest bidder's bid
     * \param bid Highest bid
     */
    void SetBid(double bid);
};