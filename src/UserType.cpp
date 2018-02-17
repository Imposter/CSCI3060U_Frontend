#include "UserType.hpp"

std::string GetUserTypeString(UserType type)
{
	switch (type)
	{
	case kUserType_Buy:
		return "BS";
	case kUserType_Sell:
		return "SS";
	case kUserType_Full:
		return "FS";
	case kUserType_Admin:
		return "AA";
	}

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

	return kUserType_Buy;
}
