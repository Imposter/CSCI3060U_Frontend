#include "UserType.hpp"

std::string GetUserTypeString(UserType type)
{
	if (type == kUserType_Buy)
		return "BS";
	if (type == kUserType_Sell)
		return "SS";
	if (type == kUserType_Full)
		return "FS";
	if (type == kUserType_Admin)
		return "AA";

	return "";
}

std::string GetUserTypeLongString(UserType type)
{
	if (type == kUserType_Buy)
		return "buy-standard";
	if (type == kUserType_Sell)
		return "sell-standard";
	if (type == kUserType_Full)
		return "full-standard";
	if (type == kUserType_Admin)
		return "admin";

	return "";
}

UserType GetUserTypeFromString(std::string &type)
{
	if (type == "BS")
		return kUserType_Buy;
	if (type == "SS")
		return kUserType_Sell;
	if (type == "FS")
		return kUserType_Full;
	if (type == "AA")
		return kUserType_Admin;

	return kUserType_None;
}

UserType GetUserTypeFromLongString(std::string &type)
{
	if (type == "buy-standard")
		return kUserType_Buy;
	if (type == "sell-standard")
		return kUserType_Sell;
	if (type == "full-standard")
		return kUserType_Full;
	if (type == "admin")
		return kUserType_Admin;

	return kUserType_None;
}
