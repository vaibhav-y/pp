#include <gtest/gtest.h>
#include <utility>

#include "reverseInteger.h"

class P0007_ReverseInteger
    : public ::testing::TestWithParam<std::pair<int, int>> {
protected:
  p0007::Solution sol;
};

class P0007_ReverseSingleDigit : public ::testing::TestWithParam<int> {
protected:
  p0007::Solution sol;
};

/* Single digit tests */
INSTANTIATE_TEST_CASE_P(Invariance, P0007_ReverseSingleDigit,
                        ::testing::Values(0, 1, -1, 2, -2, 3, -3, 4, -4, 5, -5,
                                          6, -6, 7, -7, 8, -8, 9, -9));

TEST_P(P0007_ReverseSingleDigit, Invariance) {
  EXPECT_EQ(sol.reverse(GetParam()), GetParam());
}

/* Multi-digit tests */
INSTANTIATE_TEST_CASE_P(
    Reverse, P0007_ReverseInteger,
    ::testing::Values(
        std::make_pair(210002000, 200012),
        std::make_pair(-301008090, -90800103), std::make_pair(1234567, 7654321),
        std::make_pair(2147483647, 0), std::make_pair(-2147483648, 0),
        std::make_pair(-2147483647, 0), std::make_pair(-2147483646, 0),
        std::make_pair(-2147483624, 0), std::make_pair(-2147483643, 0),
        std::make_pair(1534236469, 0), std::make_pair(2147483641, 1463847412)));

TEST_P(P0007_ReverseInteger, Generic) {
  EXPECT_EQ(sol.reverse(GetParam().first), GetParam().second);
}
