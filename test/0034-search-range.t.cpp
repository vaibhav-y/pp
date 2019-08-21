#include <gtest/gtest.h>
#include <utility>
#include <vector>

#include "searchRange.h"

typedef std::pair<std::vector<int>, int> INPUT;
typedef std::vector<int> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0034_SeachRange : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0034::Solution sol;
};

INSTANTIATE_TEST_CASE_P(SearchRangeTest, P0034_SeachRange,
  ::testing::Values(
    t({{}, 0}, {-1, -1}),
    t({{1, 1}, 1}, {0, 1}),
    t({{2, 2, 2}, 2}, {0, 2}),
    t({{}, {}}, {})
  )
);

TEST_P(P0034_SeachRange, Generic) {
  auto input = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.searchRange(input.first, input.second));
}
