#pragma once

#include <memory>

class PointerCast
{
    template<typename TTo, typename TFrom>
	static std::shared_ptr<TTo> Reinterpret(const std::shared_ptr<TFrom> &from) noexcept;
};