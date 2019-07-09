#include <gtest/gtest.h>
#include <vector>
#include <utility>

typedef std::vector<std::vector<int>> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

#include "minPathSum.h"

class P0064_MinPathSum : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0064::Solution sol;
};

INSTANTIATE_TEST_CASE_P(MinPathSumTest, P0064_MinPathSum,
  ::testing::Values(
    t({}, 0),
    t({{1, 2, 3}}, 6),
    t({{1}, {2}, {3}}, 6),
    t({{1, 1, 1}, {1, 2, 1}}, 4),
    t({{1, 3, 1}, {1, 5 ,1}, {4, 2, 1}}, 7),
    t({{1, 3, 1}, {1, -3 ,1}, {4, 2, 1}}, 1)
  )
);

TEST_P(P0064_MinPathSum, Generic) {
  EXPECT_EQ(GetParam().second,
    sol.minPathSum(const_cast<INPUT&>(GetParam().first))
  );
}
