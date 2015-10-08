//
// Created by Massimo Biancalani on 04/10/15.
//
#include "3n_1.h"
#include <gtest/gtest.h>
TEST(Main,Cycle_Length){
    EXPECT_EQ(16,Cycle_Length(22));
    EXPECT_EQ(7,Cycle_Length(10));
    EXPECT_EQ(153,Cycle_Length(1000000));
}

TEST(Main,Max_Cycle_Length){
    EXPECT_EQ(20, Max_Cycle_Length(1, 10));
    EXPECT_EQ(125, Max_Cycle_Length(100, 200));
    EXPECT_EQ(321, Max_Cycle_Length(999000, 999250));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}