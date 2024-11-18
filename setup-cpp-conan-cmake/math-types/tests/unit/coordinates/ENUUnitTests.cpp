#include <gtest/gtest.h>
#include "coordinates/ENU.h"
#include <sstream>
#include <iostream>

// Test case for default constructor
TEST(ENUTest, DefaultConstructor) {
    ENU enu;  // Default constructor
    EXPECT_DOUBLE_EQ(enu.getX(), 0.0);  // Expect east to be 0.0
    EXPECT_DOUBLE_EQ(enu.getY(), 0.0);  // Expect north to be 0.0
    EXPECT_DOUBLE_EQ(enu.getZ(), 0.0);  // Expect up to be 0.0
}

// Test case for parameterized constructor
TEST(ENUTest, ParameterizedConstructor) {
    ENU enu(1.0, 2.0, 3.0);  // Parameterized constructor
    EXPECT_DOUBLE_EQ(enu.getX(), 1.0);  // Expect east to be 1.0
    EXPECT_DOUBLE_EQ(enu.getY(), 2.0);  // Expect north to be 2.0
    EXPECT_DOUBLE_EQ(enu.getZ(), 3.0);  // Expect up to be 3.0
}

// Test case for printCoordinates() function
TEST(ENUTest, PrintCoordinates) {
    ENU enu(1.0, 2.0, 3.0);

    // Capture the output of printCoordinates() using a stringstream
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    enu.printCoordinates();
    std::cout.rdbuf(oldCout);

    // Check that the output matches the expected format
    EXPECT_EQ(buffer.str(), "ENU Coordinates: (1, 2, 3)\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}