//
// Created by Massimo Biancalani on 23/04/16.
//

#include "gtest/gtest.h"
#include "lcd_display.cpp"


TEST(lcd_display_check, display0_length1) {

    // tests go here
    testing::internal::CaptureStdout();
    show("0", 1);
    string output = testing::internal::GetCapturedStdout();
    string expectedOutput = " - \n"
                            "| |\n"
                            "   \n"
                            "| |\n"
                            " - \n";

    EXPECT_STREQ(expectedOutput.c_str(), output.c_str());
}

TEST(lcd_display_check, display0_length2) {

    // tests go here
    testing::internal::CaptureStdout();
    show("0", 2);
    string output = testing::internal::GetCapturedStdout();
    string expectedOutput = " -- \n"
                            "|  |\n"
                            "|  |\n"
                            "    \n"
                            "|  |\n"
                            "|  |\n"
                            " -- \n";
    EXPECT_STREQ(expectedOutput.c_str(), output.c_str());
}

TEST(lcd_display_check, display2_length2) {

    // tests go here
    testing::internal::CaptureStdout();
    show("2", 2);
    string output = testing::internal::GetCapturedStdout();
    string expectedOutput = " -- \n"
                            "   |\n"
                            "   |\n"
                            " -- \n"
                            "|   \n"
                            "|   \n"
                            " -- \n";
    EXPECT_STREQ(expectedOutput.c_str(), output.c_str());
}

TEST(lcd_display_check, display0_length2_2_digits) {

    // tests go here
    testing::internal::CaptureStdout();
    show("01", 1);
    string output = testing::internal::GetCapturedStdout();
    string expectedOutput = " -     \n"
                            "| |   |\n"
                            "       \n"
                            "| |   |\n"
                            " -     \n";
    EXPECT_STREQ(expectedOutput.c_str(), output.c_str());
}

TEST(lcd_display_check, display_example) {
    std::streambuf* orig = std::cin.rdbuf();
    std::istringstream input("2 12345\n"
                                     "3 67890\n"
                                     "0 0");
    std::cin.rdbuf(input.rdbuf());

    // tests go here
    testing::internal::CaptureStdout();
    display();
    string output = testing::internal::GetCapturedStdout();
    string expectedOutput = "      --   --        -- \n"
                            "   |    |    | |  | |   \n"
                            "   |    |    | |  | |   \n"
                            "      --   --   --   -- \n"
                            "   | |       |    |    |\n"
                            "   | |       |    |    |\n"
                            "      --   --        -- \n"
                            "\n"
                            " ---   ---   ---   ---   --- \n"
                            "|         | |   | |   | |   |\n"
                            "|         | |   | |   | |   |\n"
                            "|         | |   | |   | |   |\n"
                            " ---         ---   ---       \n"
                            "|   |     | |   |     | |   |\n"
                            "|   |     | |   |     | |   |\n"
                            "|   |     | |   |     | |   |\n"
                            " ---         ---   ---   --- \n"
                            "\n";
    std::cin.rdbuf(orig);
    EXPECT_STREQ(expectedOutput.c_str(), output.c_str());
}
