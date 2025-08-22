#include "order_book.hpp"

#include <gtest/gtest.h>

using namespace ullts;

TEST(OrderBook, AddOrder) {
  OrderBook book;
  Order order(1, "AAPL", OrderSide::Buy, 150.25, 100);
  book.add_order(order);

  auto retrieved_order = book.get_order(1);
  EXPECT_TRUE(retrieved_order.has_value());
  EXPECT_EQ(retrieved_order->id, 1);
}

TEST(OrderBook, CancelOrder) {
  OrderBook book;
  Order order(1, "AAPL", OrderSide::Buy, 150.25, 100);
  book.add_order(order);

  EXPECT_TRUE(book.cancel_order(1));
  EXPECT_FALSE(book.get_order(1).has_value());
}

TEST(OrderBook, CancelNonExistentOrder) {
  OrderBook book;
  EXPECT_FALSE(book.cancel_order(1));
}

TEST(OrderBook, GetOrder) {
  OrderBook book;
  Order order(1, "AAPL", OrderSide::Buy, 150.25, 100);
  book.add_order(order);

  auto retrieved_order = book.get_order(1);
  EXPECT_TRUE(retrieved_order.has_value());
  EXPECT_EQ(retrieved_order->symbol, "AAPL");
}

TEST(OrderBook, GetAllOrders) {
  OrderBook book;
  book.add_order(Order(1, "AAPL", OrderSide::Buy, 150.25, 100));
  book.add_order(Order(2, "GOOG", OrderSide::Sell, 2700.50, 50));

  auto all_orders = book.get_all_orders();
  EXPECT_EQ(all_orders.size(), 2);
}

TEST(OrderBook, Clear) {
  OrderBook book;
  book.add_order(Order(1, "AAPL", OrderSide::Buy, 150.25, 100));
  book.add_order(Order(2, "GOOG", OrderSide::Sell, 2700.50, 50));

  book.clear();
  EXPECT_EQ(book.get_all_orders().size(), 0);
}
