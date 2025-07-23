#include "order_book.hpp"

#include <optional>
#include <vector>

namespace ullts {
void OrderBook::add_order(const Order& /*order*/) {}

bool OrderBook::cancel_order(std::uint64_t /*order_id*/) { return false; };

std::optional<ullts::Order> OrderBook::get_order(
    std::uint64_t /*order_id*/) const {
  return std::nullopt;
}

std::vector<Order> OrderBook::get_all_orders() const { return {}; }

void OrderBook::clear() noexcept {}
}  // namespace ullts
