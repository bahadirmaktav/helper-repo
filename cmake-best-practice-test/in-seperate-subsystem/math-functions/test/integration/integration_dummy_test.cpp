#include <gtest/gtest.h>

int Substract(int a, int b) {
    return a - b;
}

TEST(SubstractTests, TwoPositiveNumbers) {
    EXPECT_EQ(Substract(5, 2), 3);
}