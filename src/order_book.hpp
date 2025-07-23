#pragma once

#include "order.hpp"
#include <vector>
#include <optional>
#include <cstdint>

namespace ullts
{
    class OrderBook
    {
    public:
        // Rule of 5 - explicitly defaulted for clarity
        OrderBook() = default;
        OrderBook(const OrderBook &) = default;
        OrderBook &operator=(const OrderBook &) = default;
        OrderBook(OrderBook &&) noexcept = default;
        OrderBook &operator=(OrderBook &&) noexcept = default;
        ~OrderBook() = default;

        // Add a new order to the book
        void add_order(const Order &order);

        // Cancel order by ID, returns true if successful
        [[nodiscard]] bool cancel_order(std::uint64_t order_id);

        // Try to find an order by ID
        [[nodiscard]] std::optional<ullts::Order> get_order(std::uint64_t order_id) const;

        // Get all open orders (for test/inspection)
        [[nodiscard]] std::vector<Order> get_all_orders() const;

        // Clear the order book
        void clear() noexcept;

    private:
        std::vector<Order> orders_{};
    };
}