#pragma once

#include <string>
#include <memory>

/**
 * \brief Provides an interface to serialize data into STL strings or deserialize them into target types
 * \tparam TData Serializer type data to serialize
 */
template <typename TData>
class ISerializer
{
public:
	/**
	 * \brief Virtual default destructor
	 */
	virtual ~ISerializer() = default;

	/**
	 * \brief Serialize an object into a string
	 * \param data Target data to serialize
	 * \return Data serialized into a string
	 */
	virtual std::string Serialize(std::shared_ptr<TData> data) = 0;

	/**
	 * \brief Deserialize string into an object
	 * \param serializedData Serialized data to deserialize into target data type
	 * \return Deserialized type
	 */
	virtual std::shared_ptr<TData> Deserialize(std::string serializedData) = 0;
};