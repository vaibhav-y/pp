#include <gtest/gtest.h>
#include <vector>
#include <utility>

#include "maxProfit.h"


typedef std::vector<int> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0121_MaxProfit : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0121::Solution sol;
};

INSTANTIATE_TEST_CASE_P(MaxProfitTest, P0121_MaxProfit,
  ::testing::Values(
    t({1}, 0),
    t({2, 1}, 0),
    t({1, 2}, 1),
    t({7,6,4,3,1}, 0),
    t({7,1,5,3,6,4}, 5),
    t({1,2,3,4,5,6,7}, 6),
    t({1,2,3,3, 100, 4, 101}, 100)
  )
);

TEST_P(P0121_MaxProfit, Generic) {
  EXPECT_EQ(
    GetParam().second,
    sol.maxProfit(const_cast<INPUT&>(GetParam().first))
  );
}
