#pragma once
#include <cstdint>
#include <string>

enum class OrderSide
{
    Buy,
    Sell
};

struct Order
{
    uint64_t id;
    OrderSide side;
    double price;
    uint32_t quantity;
    std::string symbol;
};
