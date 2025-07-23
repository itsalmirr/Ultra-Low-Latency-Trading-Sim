#pragma once

#include <chrono>
#include <cstdint>
#include <string>
#include <string_view>

namespace ullts {

enum class OrderSide : std::uint8_t { Buy, Sell };

struct Order {
  std::uint64_t id{};
  std::string symbol{};
  OrderSide side{OrderSide::Buy};
  double price{};
  std::uint32_t quantity{};
  std::chrono::nanoseconds timestamp{};

  // Rule of 5 - explicitly defaulted
  Order() = default;
  Order(const Order &) = default;
  Order &operator=(const Order &) = default;
  Order(Order &&) noexcept = default;
  Order &operator=(Order &&) noexcept = default;
  ~Order() = default;
};
}  // namespace ullts
