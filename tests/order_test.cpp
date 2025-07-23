#include <gtest/gtest.h>
#include "order.hpp"

using namespace ullts;

TEST(Order, Construction)
{
    Order order{};
    order.id = 1;
    order.symbol = "AAPL";
    order.side = OrderSide::Buy;
    order.price = 150.25;
    order.quantity = 100;

    EXPECT_EQ(order.id, 1);
    EXPECT_EQ(order.symbol, "AAPL");
    EXPECT_EQ(order.side, OrderSide::Buy);
    EXPECT_DOUBLE_EQ(order.price, 150.25);
    EXPECT_EQ(order.quantity, 100);
}
