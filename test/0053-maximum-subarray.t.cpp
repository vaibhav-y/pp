#include <gtest/gtest.h>
#include <utility>
#include <0053/maxSubArray.h>

#include <vector>

typedef std::vector<int> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0053_MaxSubArray : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0053::Solution sol;
};


INSTANTIATE_TEST_CASE_P(MaxSubArrayTest, P0053_MaxSubArray,
  ::testing::Values(
    t({-1,-1,-1,-1}, -1),
    t({-4,-3,-2,-1}, -1),
    t({-2}, -2),
    t({-2,1}, 1),
    t({-2,1,-3}, 1),
    t({-2,1,-3,4}, 4),
    t({-2,1,-3,4,-1}, 4),
    t({-2,1,-3,4,-1,2}, 5),
    t({-2,1,-3,4,-1,2,1}, 6),
    t({-2,1,-3,4,-1,2,1,-5}, 6),
    t({-2,1,-3,4,-1,2,1,-5,4}, 6)
));

TEST_P(P0053_MaxSubArray, Generic) {
  auto input = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.maxSubArray(input));
}
