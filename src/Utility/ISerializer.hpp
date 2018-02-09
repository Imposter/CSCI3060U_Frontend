#pragma once

#include <string>
#include <memory>

template <typename TData>
class ISerializer
{
public:
	virtual ~ISerializer() = default;

	virtual std::string Serialize(std::shared_ptr<TData> data) = 0;
	virtual std::shared_ptr<TData> Deserialize(std::string serializedData) = 0;
};