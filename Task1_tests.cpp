//
// Created by valera on 14.09.18.
//
// tests.cpp
#include "main.cpp"
#include <gtest/gtest.h>

TEST(EqualsTest, Test1) {
    double x1=-2,x2=-2;
    ASSERT_EQ(1, SolveEquation(1,4,4,x1,x2));
}

TEST(EqualsTest, Test2) {
    double x1=-5,x2=-0.25;
    ASSERT_EQ(1, SolveEquation(4,21,5,x1,x2));
}

TEST(EqualsTest, Test3) {
    double x1=9,x2=-30;
    ASSERT_EQ(1, SolveEquation(9,-30,25,x1,x2));
}

TEST(EqualsTest, Test4) {
    double x1=1,x2=3.5;
    ASSERT_EQ(1, SolveEquation(2,-9,7,x1,x2));
}

TEST(EqualsTest, Test5) {
    double x1=3,x2=3;
    ASSERT_EQ(1, SolveEquation(3,-18,27,x1,x2));
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
