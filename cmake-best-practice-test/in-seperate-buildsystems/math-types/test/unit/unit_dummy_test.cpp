#include <gtest/gtest.h>

int Add(int a, int b) {
    return a + b;
}

TEST(AddTests, TwoPositiveNumbers) {
    EXPECT_EQ(Add(1, 2), 3);
}