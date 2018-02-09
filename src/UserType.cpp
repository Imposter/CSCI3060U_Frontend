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
