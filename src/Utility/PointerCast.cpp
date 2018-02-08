#include "PointerCast.hpp"

template<typename TTo, typename TFrom>
std::shared_ptr<TTo> PointerCast::Reinterpret(const std::shared_ptr<TFrom> &from) noexcept
{
    auto pointer = reinterpret_cast<typename std::shared_ptr<TTo>::element_type *>(from.get());
    return std::shared_ptr<TTo>(from, pointer);
}