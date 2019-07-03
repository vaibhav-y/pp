#include <gtest/gtest.h>

#include <vector>
#include <utility>

#include "maxSubArray.h"


typedef int OUTPUT;
typedef std::vector<int> INPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto& t = std::make_pair<INPUT, OUTPUT>;

class P053_MaxSubarray : public ::testing::TestWithParam<TESTCASE> {
protected:
  p053::Solution sol;
};

INSTANTIATE_TEST_CASE_P(MaximumSumSubarrayTest, P053_MaxSubarray,
                        ::testing::Values(
                          t({1}, 1),
                          t({-1}, -1),
                          t({-1, 2}, 2),
                          t({2, -1}, 2),
                          t({2, -1, -1}, 2),
                          t({2, 1, 3}, 6),
                          t({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6)
                        ));

TEST_P(P053_MaxSubarray, Generic) {
  EXPECT_EQ(GetParam().second,
            sol.maxSubArray(const_cast<INPUT&>(GetParam().first)));
}
