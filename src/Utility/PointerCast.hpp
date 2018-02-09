#pragma once

#include <memory>

class PointerCast
{
public:
    template<typename TTo, typename TFrom>
	static std::shared_ptr<TTo> Reinterpret(const std::shared_ptr<TFrom> &from)
	{
		auto pointer = reinterpret_cast<typename std::shared_ptr<TTo>::element_type *>(from.get());
		return std::shared_ptr<TTo>(from, pointer);
	}
};