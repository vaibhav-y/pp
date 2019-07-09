#include <gtest/gtest.h>
#include <utility>

#include "atoi.h"

class P008_CustomAtoi
    : public ::testing::TestWithParam<std::pair<std::string, int>> {
protected:
  p008::Solution sol;
};

INSTANTIATE_TEST_CASE_P(
    AtoiTest, P008_CustomAtoi,
    ::testing::Values(std::make_pair("42", 42), std::make_pair("02", 2),
                      std::make_pair("20", 20), std::make_pair("-123", -123),
                      std::make_pair("-123", -123),
                      std::make_pair("                     -562", -562),
                      std::make_pair("                 52", 52),
                      std::make_pair("4294967295", 2147483647),
                      std::make_pair("4,294,967,295", 4),
                      std::make_pair("words before 9", 0),
                      std::make_pair("8905 before words", 8905),
                      std::make_pair("2147483647", 2147483647),
                      std::make_pair("-2147483648", -2147483648),
                      std::make_pair("2147483648", 2147483647),
                      std::make_pair("2147483646", 2147483646),
                      std::make_pair("+214748364", 214748364)));

TEST_P(P008_CustomAtoi, Generic) {
  EXPECT_EQ(sol.myAtoi(GetParam().first), GetParam().second);
}
