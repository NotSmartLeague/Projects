#include <googletest-1.15.2/googletest/include/gtest/gtest.h>
#include "../src/main.cpp"

TEST(CalculatorTests, Addition){
    EXPECT_DOUBLE_EQ(add(3.0, 2.0), 5.0);
    EXPECT_DOUBLE_EQ(add(-1.0, 1.0), 0.0);
    EXPECT_DOUBLE_EQ(add(0.0, 0.0), 0.0);
}

