#pragma once

#include <memory>

/**
 * \brief Implements missing functionality from STL shared_ptr pointer casting
 */
class PointerCast
{
public:
	/**
     * \brief Implementation of missing std::reinterpret_pointer_cast, to cast std::shared_ptr<TFrom> to std::shared_ptr<TTo> 
     * \tparam TTo Target type
     * \tparam TFrom Source type
     * \param from Source object
     * \return Source casted to target type
     */
    template<typename TTo, typename TFrom>
	static std::shared_ptr<TTo> Reinterpret(const std::shared_ptr<TFrom> &from)
	{
		auto pointer = reinterpret_cast<typename std::shared_ptr<TTo>::element_type *>(from.get());
		return std::shared_ptr<TTo>(from, pointer);
	}
};