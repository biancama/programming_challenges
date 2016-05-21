//
// Created by Massimo Biancalani on 23/04/16.
//

#include "gtest/gtest.h"
#include "the_trip.cpp"

TEST(the_trip_check, get_cents) {

    EXPECT_EQ(get_cents("15.01"), 1501);
    EXPECT_EQ(get_cents("199.91"), 19991);
    EXPECT_EQ(get_cents("100000.00"), 10000000);
}

TEST(the_trip_check, get_average01) {
    unsigned int amounts [] = {10000, 20000, 30000};
    EXPECT_EQ(get_average(amounts, 3), 20000);
}

TEST(the_trip_check, get_average02) {
    unsigned int amounts [] = {1500, 1501, 300, 301};
    EXPECT_EQ(get_average(amounts, 4), 901);
}

TEST(the_trip_check, trips01) {
    std::streambuf* orig = std::cin.rdbuf();
    std::istringstream input("3\n"
                                     "10.00\n"
                                     "20.00\n"
                                     "30.00\n"
                                     "4\n"
                                     "15.00\n"
                                     "15.01\n"
                                     "3.00\n"
                                     "3.01\n"
                                     "0\n");
    std::cin.rdbuf(input.rdbuf());

    // tests go here
    testing::internal::CaptureStdout();
    trips();
    string output = testing::internal::GetCapturedStdout();
    string expectedOutput = "$10.00\n"
            "$11.99\n";

    std::cin.rdbuf(orig);
    EXPECT_STREQ(expectedOutput.c_str(), output.c_str());
}

TEST(the_trip_check, trips02) {
    std::streambuf* orig = std::cin.rdbuf();
    std::istringstream input("4\n"
                                     "0.01\n"
                                     "0.05\n"
                                     "0.05\n"
                                     "0.07\n"
                                     "0\n");
    std::cin.rdbuf(input.rdbuf());

    // tests go here
    testing::internal::CaptureStdout();
    trips();
    string output = testing::internal::GetCapturedStdout();
    string expectedOutput = "$0.02\n";

    std::cin.rdbuf(orig);
    EXPECT_STREQ(expectedOutput.c_str(), output.c_str());
}