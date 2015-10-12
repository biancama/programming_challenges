//
// Created by Massimo Biancalani on 08/10/15.
//

#include "Minesweeper.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace testing;

TEST(Minesweeper, adjacentMines01){

   Minesweeper minesweeper(4, 4);
    minesweeper.addMine(0, "*...");
    minesweeper.addMine(1, "....");
    minesweeper.addMine(2, ".*..");
    minesweeper.compute();
    char expectedTable[4][4] = {{'*','1', '0', '0'}, {'2','2', '1', '0'}, {'1','*', '1', '0'}, {'1','1', '1', '0'}};
    for (int i = 0; i < 4; ++i) {
        EXPECT_TRUE( 0 == std::memcmp( expectedTable[i], minesweeper.getTable()[i], sizeof( expectedTable[i] ) ) );
    }
}

TEST(Minesweeper, adjacentMines02){
    Minesweeper minesweeper(3, 5);
    minesweeper.addMine(0, "**...");
    minesweeper.addMine(1, ".....");
    minesweeper.addMine(2, ".*...");
    minesweeper.compute();
    char expectedTable[3][5] = {{'*','*', '1', '0', '0'}, {'3','3', '2', '0', '0'}, {'1','*', '1', '0', '0'}};
    for (int i = 0; i < 3; ++i) {
        EXPECT_TRUE( 0 == std::memcmp( expectedTable[i], minesweeper.getTable()[i], sizeof( expectedTable[i] ) ) );
    }
}

TEST(Minesweeper, adjacentMines03){

    Minesweeper minesweeper(4, 4);
    minesweeper.addMine(0, "*...");
    minesweeper.addMine(1, ".*..");
    minesweeper.addMine(2, "..*.");
    minesweeper.addMine(3, "...*");
    minesweeper.compute();
    char expectedTable[4][4] = {{'*','2', '1', '0'}, {'2','*', '2', '1'}, {'1','2', '*', '2'}, {'0','1', '2', '*'}};
    for (int i = 0; i < 4; ++i) {
        EXPECT_TRUE( 0 == std::memcmp( expectedTable[i], minesweeper.getTable()[i], sizeof( expectedTable[i] ) ) );
    }
}

TEST(Minesweeper, adjacentMines04){

    Minesweeper minesweeper(4, 4);
    minesweeper.addMine(0, "****");
    minesweeper.addMine(1, "****");
    minesweeper.addMine(2, "****");
    minesweeper.addMine(3, "****");
    minesweeper.compute();
    char expectedTable[4][4] = {{'*','*', '*', '*'}, {'*','*', '*', '*'}, {'*','*', '*', '*'}, {'*','*', '*', '*'}};
    for (int i = 0; i < 4; ++i) {
        EXPECT_TRUE( 0 == std::memcmp( expectedTable[i], minesweeper.getTable()[i], sizeof( expectedTable[i] ) ) );
    }
}

TEST(Minesweeper, adjacentMines05){

    Minesweeper minesweeper(4, 4);
    minesweeper.addMine(0, "....");
    minesweeper.addMine(1, "....");
    minesweeper.addMine(2, "....");
    minesweeper.addMine(3, "....");
    minesweeper.compute();
    char expectedTable[4][4] = {{'0','0', '0', '0'}, {'0','0', '0', '0'}, {'0','0', '0', '0'}, {'0','0', '0', '0'}};
    for (int i = 0; i < 4; ++i) {
        EXPECT_TRUE( 0 == std::memcmp( expectedTable[i], minesweeper.getTable()[i], sizeof( expectedTable[i] ) ) );
    }
}

TEST(Minesweeper, adjacentMines06){

    Minesweeper minesweeper(4, 4);
    minesweeper.addMine(0, "*.*.");
    minesweeper.addMine(1, ".*.*");
    minesweeper.addMine(2, "*.*.");
    minesweeper.addMine(3, ".*.*");
    minesweeper.compute();
    char expectedTable[4][4] = {{'*','3', '*', '2'}, {'3','*', '4', '*'}, {'*','4', '*', '3'}, {'2','*', '3', '*'}};
        for (int i = 0; i < 4; ++i) {
            EXPECT_TRUE( 0 == std::memcmp( expectedTable[i], minesweeper.getTable()[i], sizeof( expectedTable[i] ) ) );
        }
}

TEST(Minesweeper, adjacentMines07){

    Minesweeper minesweeper(6, 6);
    minesweeper.addMine(0, "......");
    minesweeper.addMine(1, "******");
    minesweeper.addMine(2, "......");
    minesweeper.addMine(3, "******");
    minesweeper.addMine(4, "......");
    minesweeper.addMine(5, "******");
    minesweeper.compute();
    char expectedTable[6][6] = {{'2','3', '3', '3', '3', '2'}, {'*','*', '*', '*', '*', '*'}, {'4','6', '6', '6', '6', '4'}, {'*','*', '*', '*', '*', '*'}, {'4','6', '6', '6', '6', '4'}, {'*','*', '*', '*', '*', '*'}};
    for (int i = 0; i < 6; ++i) {
        EXPECT_TRUE( 0 == std::memcmp( expectedTable[i], minesweeper.getTable()[i], sizeof( expectedTable[i] ) ) );
    }
}

TEST(Minesweeper, adjacentMines08){

    Minesweeper minesweeper(1, 1);
    minesweeper.addMine(0, ".");
    minesweeper.compute();
    char expectedTable[1][1] = {{'0'}};
    for (int i = 0; i < 1; ++i) {
        EXPECT_TRUE( 0 == std::memcmp( expectedTable[i], minesweeper.getTable()[i], sizeof( expectedTable[i] ) ) );
    }
}

TEST(Minesweeper, adjacentMines09){

    Minesweeper minesweeper(1, 1);
    minesweeper.addMine(0, "*");
    minesweeper.compute();
    char expectedTable[1][1] = {{'*'}};
    for (int i = 0; i < 1; ++i) {
        EXPECT_TRUE( 0 == std::memcmp( expectedTable[i], minesweeper.getTable()[i], sizeof( expectedTable[i] ) ) );
    }
}

TEST(Minesweeper, adjacentMines10){

    Minesweeper minesweeper(1, 7);
    minesweeper.addMine(0, ".*.*.*.");
    minesweeper.compute();
    char expectedTable[1][7] = {'1', '*','2','*','2','*','1'};
    for (int i = 0; i < 1; ++i) {
        EXPECT_TRUE( 0 == std::memcmp( expectedTable[i], minesweeper.getTable()[i], sizeof( expectedTable[i] ) ) );
    }
}

TEST(Minesweeper, adjacentMines11){

    Minesweeper minesweeper(7, 1);
    minesweeper.addMine(0, ".");
    minesweeper.addMine(1, "*");
    minesweeper.addMine(2, ".");
    minesweeper.addMine(3, "*");
    minesweeper.addMine(4, ".");
    minesweeper.addMine(5, "*");
    minesweeper.addMine(6, ".");
    minesweeper.compute();
    char expectedTable[7][1] = {{'1'}, {'*'},{'2'},{'*'},{'2'},{'*'},{'1'}};
    for (int i = 0; i < 7; ++i) {
        EXPECT_TRUE( 0 == std::memcmp( expectedTable[i], minesweeper.getTable()[i], sizeof( expectedTable[i] ) ) );
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::GTEST_FLAG(filter) = "Minesweeper.adjacentMines*";
    return RUN_ALL_TESTS();
}
