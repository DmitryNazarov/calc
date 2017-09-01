#include <gtest/gtest.h>
#include <calc.h>

TEST(IncorrectInputs, EmptyInput)
{
    std::istringstream input("");
    getToken(input);

    ASSERT_EQ(END, currTok);
}

TEST(IncorrectInputs, ZeroDivision)
{
    std::istringstream input("1/0");
    ASSERT_EQ(1, calc(input));
}

TEST(IncorrectInputs, StrangeInput1)
{
    std::istringstream input("0.001+0,001");
    ASSERT_EQ(0.002, calc(input));
}

TEST(IncorrectInputs, StrangeInput2)
{
    std::istringstream input(".1+,1");
    ASSERT_EQ(0.2, calc(input));
}

TEST(IncorrectInputs, StrangeInput3)
{
    std::istringstream input("+-1");
    ASSERT_EQ(0, calc(input));
}

TEST(IncorrectInputs, StrangeInput4)
{
    std::istringstream input("1*/2");
    ASSERT_EQ(0.5, calc(input));
}

TEST(IncorrectInputs, StrangeInput5)
{
    std::istringstream input("1.01.01 + 1");
    ASSERT_EQ(2.0101, calc(input));
}

TEST(IncorrectInputs, UnbalansedBrackets)
{
    std::istringstream input("3-(2-1");
    ASSERT_EQ(2, calc(input));
}

TEST(CalcTests, 1)
{
    std::istringstream input("-1 + 5 - 3");
    ASSERT_EQ(1, calc(input));
}

TEST(CalcTests, 2)
{
    std::istringstream input("-10 + (8*2.5) - (3 / 1,5)");
    ASSERT_EQ(8, calc(input));
}

TEST(CalcTests, 3)
{
    std::istringstream input("1 + (2* (2.5 + 2.5 + (3 - 2))) - (3 / 1.5)");
    ASSERT_EQ(11, calc(input));
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
