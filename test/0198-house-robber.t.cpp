#include <gtest/gtest.h>
#include <utility>
#include <vector>

#include "rob.h"

typedef std::vector<int> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0198_HouseRobber : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0198::Solution sol;
};

INSTANTIATE_TEST_CASE_P(HouseRobberTest, P0198_HouseRobber,
  ::testing::Values(
    t({1}, 1),
    t({1, 2}, 2),
    t({2, 1}, 2),
    t({1, 2, 3, 1}, 4),
    t({2, 7, 9, 3, 1}, 12),
    t({2, 1, 4, 3, 5, 1000, 7, 8, 6}, 1014)
  )
);

TEST_P(P0198_HouseRobber, Generic) {
  EXPECT_EQ(
    GetParam().second,
    sol.rob(const_cast<INPUT&>(GetParam().first))
  );
}
