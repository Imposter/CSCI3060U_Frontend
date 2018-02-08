#pragma once

#include <string>

template <typename TData>
class ISerializer
{
public:
	virtual ~ISerializer() = default;

	virtual std::string Serialize(TData data) = 0;
	virtual TData Deserialize(std::string serializedData) = 0;
};