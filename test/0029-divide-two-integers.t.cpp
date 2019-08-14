#include <gtest/gtest.h>
#include <utility>

#include "divide.h"

typedef std::pair<int, int> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0029_DivideTwoIntegers : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0029::Solution sol;
};

INSTANTIATE_TEST_CASE_P(DivideTwoIntegers, P0029_DivideTwoIntegers,
  ::testing::Values(
    t({-2, 1}, -2),
    t({10, 3}, 3),
    t({7, 2}, 3),
    t({7, -3}, -2),
    t({1, 0}, 2147483647),
    t({-1, 0}, 2147483647),
    t({2147483647, 54}, 39768215),
    t({-2147483648, 54}, -39768215),
    t({-2147483648, 2147483647}, -1),
    t({-2147483648, 2147483647 >> 1}, -2),
    t({-2147483648, -123}, 17459216),
    t({-2147483648, -2147483647}, 1),
    t({-2147483648, 2147483647}, -1),
    t({2147483647, -2147483648}, 0)
  )
);

TEST_P(P0029_DivideTwoIntegers, Generic) {
  auto input = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.divide(input.first, input.second));
}
