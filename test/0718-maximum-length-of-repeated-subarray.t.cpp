#include <gtest/gtest.h>
#include <utility>
#include <vector>

#include "findCommonSubarrayLength.h"

typedef std::vector<int> LIST;
typedef std::pair<LIST, LIST> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0718_FindCommonSubarrayLength
    : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0718::Solution sol;
};

INSTANTIATE_TEST_CASE_P(LongestCommonSubarray, P0718_FindCommonSubarrayLength,
                        ::testing::Values(t({{}, {}}, 0),
                                          t({{1, 3, 2, 3, 1}, {1}}, 1),
                                          t({{1, 3, 2, 3, 1}, {2, 3}}, 2),
                                          t({{1,2,3,2,1}, {3,2,1,4,7}}, 3),
                                          t({{1,1,1,1,1,1,1,1,1,1,1}, {1,1,1,1}}, 4)));

TEST_P(P0718_FindCommonSubarrayLength, Generic) {
  auto arg = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.findLength(const_cast<LIST &>(arg.first),
                                              const_cast<LIST &>(arg.second)));
}
