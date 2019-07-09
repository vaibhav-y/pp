#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "minCostClimbingStairs.h"

typedef std::vector<int> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto& t = std::make_pair<INPUT, OUTPUT>;

class P0746_MinCostClimbingStairs : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0746::Solution sol;
};

INSTANTIATE_TEST_CASE_P(MinCostClimbingStairs, P0746_MinCostClimbingStairs,
  ::testing::Values(
    t({1, 2}, 1),
    t({2, 1}, 1),
    t({10, 15, 20}, 15),
    t({1, 100, 1, 1, 1, 100, 1, 1, 100, 1}, 6),
    t({00, 0, 0, 0}, 0),
    t({1, 2, 3, 4, 5, 6, 7, 8, 9}, 20),
    t({1, 100, 100, 100, 1, 100}, 102)
  )
);

TEST_P(P0746_MinCostClimbingStairs, Generic) {
  EXPECT_EQ(
    GetParam().second,
    sol.minCostClimbingStairs(const_cast<INPUT&>(GetParam().first))
  );
}
