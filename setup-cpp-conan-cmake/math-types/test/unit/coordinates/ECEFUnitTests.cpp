#include <gtest/gtest.h>
#include "coordinates/ECEF.h"
#include <sstream>
#include <iostream>

TEST(ECEFTest, DefaultConstructor) {
    ECEF ecef;
    EXPECT_DOUBLE_EQ(ecef.getX(), 0.0);
    EXPECT_DOUBLE_EQ(ecef.getY(), 0.0);
    EXPECT_DOUBLE_EQ(ecef.getZ(), 0.0);
}

TEST(ECEFTest, ParameterizedConstructor) {
    ECEF ecef(1.0, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(ecef.getX(), 1.0);
    EXPECT_DOUBLE_EQ(ecef.getY(), 2.0);
    EXPECT_DOUBLE_EQ(ecef.getZ(), 3.0);
}

TEST(ECEFTest, PrintCoordinates) {
    ECEF ecef(1.0, 2.0, 3.0);
    
    std::stringstream buffer;
    std::streambuf* oldCoutBuffer = std::cout.rdbuf(buffer.rdbuf());

    ecef.printCoordinates();

    std::cout.rdbuf(oldCoutBuffer);

    EXPECT_EQ(buffer.str(), "ECEF Coordinates: (1, 2, 3)\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
