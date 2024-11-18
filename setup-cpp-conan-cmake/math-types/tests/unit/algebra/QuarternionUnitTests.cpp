#include <gtest/gtest.h>
#include "algebra/Quaternion.h"
#include <cmath>
#include <sstream>

// Test case for default constructor
TEST(QuaternionTest, DefaultConstructor) {
    Quaternion q;  // Default constructor
    EXPECT_DOUBLE_EQ(q.getW(), 1.0);  // Default w should be 1.0
    EXPECT_DOUBLE_EQ(q.getX(), 0.0);  // Default x should be 0.0
    EXPECT_DOUBLE_EQ(q.getY(), 0.0);  // Default y should be 0.0
    EXPECT_DOUBLE_EQ(q.getZ(), 0.0);  // Default z should be 0.0
}

// Test case for parameterized constructor
TEST(QuaternionTest, ParameterizedConstructor) {
    Quaternion q(1.0, 2.0, 3.0, 4.0);  // Custom constructor
    EXPECT_DOUBLE_EQ(q.getW(), 1.0);
    EXPECT_DOUBLE_EQ(q.getX(), 2.0);
    EXPECT_DOUBLE_EQ(q.getY(), 3.0);
    EXPECT_DOUBLE_EQ(q.getZ(), 4.0);
}

// Test case for addition operator
TEST(QuaternionTest, AdditionOperator) {
    Quaternion q1(1.0, 2.0, 3.0, 4.0);
    Quaternion q2(5.0, 6.0, 7.0, 8.0);
    Quaternion result = q1 + q2;
    
    EXPECT_DOUBLE_EQ(result.getW(), 6.0);
    EXPECT_DOUBLE_EQ(result.getX(), 8.0);
    EXPECT_DOUBLE_EQ(result.getY(), 10.0);
    EXPECT_DOUBLE_EQ(result.getZ(), 12.0);
}

// Test case for multiplication operator
TEST(QuaternionTest, MultiplicationOperator) {
    Quaternion q1(1.0, 2.0, 3.0, 4.0);
    Quaternion q2(5.0, 6.0, 7.0, 8.0);
    Quaternion result = q1 * q2;
    
    EXPECT_DOUBLE_EQ(result.getW(), -60.0);
    EXPECT_DOUBLE_EQ(result.getX(), 12.0);
    EXPECT_DOUBLE_EQ(result.getY(), 30.0);
    EXPECT_DOUBLE_EQ(result.getZ(), 24.0);
}

// Test case for conjugate function
TEST(QuaternionTest, ConjugateFunction) {
    Quaternion q(1.0, 2.0, 3.0, 4.0);
    Quaternion conjugate = q.conjugate();
    
    EXPECT_DOUBLE_EQ(conjugate.getW(), 1.0);
    EXPECT_DOUBLE_EQ(conjugate.getX(), -2.0);
    EXPECT_DOUBLE_EQ(conjugate.getY(), -3.0);
    EXPECT_DOUBLE_EQ(conjugate.getZ(), -4.0);
}

// Test case for norm function
TEST(QuaternionTest, NormFunction) {
    Quaternion q(1.0, 2.0, 3.0, 4.0);
    EXPECT_DOUBLE_EQ(q.norm(), std::sqrt(30.0));  // sqrt(1^2 + 2^2 + 3^2 + 4^2)
}

// Test case for print function
TEST(QuaternionTest, PrintFunction) {
    Quaternion q(1.0, 2.0, 3.0, 4.0);

    // Capture the output of print() using a stringstream
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    q.print();
    std::cout.rdbuf(oldCout);

    // Check that the output matches the expected format
    EXPECT_EQ(buffer.str(), "Quaternion: (1, 2, 3, 4)\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}