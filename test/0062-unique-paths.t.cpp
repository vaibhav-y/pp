#include <gtest/gtest.h>
#include <utility>

#include "uniquePaths.h"

typedef int OUTPUT;
typedef std::pair<int, int> INPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto& t = std::make_pair<INPUT, OUTPUT>;

class P062_UniquePaths : public ::testing::TestWithParam<TESTCASE> {
protected:
  p062::Solution sol;
};

INSTANTIATE_TEST_CASE_P(UniqePathsTest, P062_UniquePaths,
                        ::testing::Values(
                          t({1, 1}, 1),
                          t({2, 1}, 1),
                          t({1, 2}, 1),
                          t({3, 1}, 1),
                          t({1, 3}, 1),
                          t({4, 1}, 1),
                          t({1, 4}, 1),
                          t({2, 2}, 2),
                          t({2, 3}, 3),
                          t({7, 3}, 28),
                          t({7, 4}, 84)
                        ));

TEST_P(P062_UniquePaths, Generic) {
  int n = GetParam().first.first;
  int m = GetParam().first.second;

  EXPECT_EQ(GetParam().second, sol.uniquePaths(n, m));
}
