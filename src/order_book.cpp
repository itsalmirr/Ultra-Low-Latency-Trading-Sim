#include "order_book.hpp"

#include <algorithm>
#include <vector>

namespace ullts {

void OrderBook::add_order(const Order &order) {
  orders_[order.id] = order;
}

bool OrderBook::cancel_order(std::uint64_t order_id) {
  return orders_.erase(order_id) > 0;
}

std::optional<Order> OrderBook::get_order(std::uint64_t order_id) const {
  if (const auto it = orders_.find(order_id); it != orders_.cend()) {
    return it->second;
  }
  return std::nullopt;
}

std::vector<Order> OrderBook::get_all_orders() const {
  std::vector<Order> all_orders;
  all_orders.reserve(orders_.size());
  for (const auto &[id, order] : orders_) {
    all_orders.push_back(order);
  }
  return all_orders;
}

void OrderBook::clear() noexcept {
  orders_.clear();
}

}  // namespace ullts
