#include <gtest/gtest.h>
#include <utility>

#include "climbStairs.h"

typedef int INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto& t = std::make_pair<INPUT, OUTPUT>;

class P0070_ClimbingStairs : public ::testing::TestWithParam<TESTCASE> {
  protected:
  p0070::Solution sol;
};

INSTANTIATE_TEST_CASE_P(ClimbingStairsTest, P0070_ClimbingStairs,
  ::testing::Values(
    t(1, 1),
    t(2, 2),
    t(3, 3),
    t(4, 5),
    t(5, 8),
    t(6, 13),
    t(10, 89),
    t(45, 1836311903)
  ));


TEST_P(P0070_ClimbingStairs, Generic) {
  EXPECT_EQ(GetParam().second,
            sol.climbStairs(GetParam().first));
}
