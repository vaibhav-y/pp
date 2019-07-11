#include <gtest/gtest.h>
#include <utility>
#include <vector>

#include "minimumTotal.h"

typedef std::vector<std::vector<int>> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0120_Triangle : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0120::Solution sol;
};

INSTANTIATE_TEST_CASE_P(TriangleMinPathTest, P0120_Triangle,
  ::testing::Values(
    t({}, 0),
    t({{1}}, 1),
    t({{1}, {2, 3}}, 3),
    t({{-1}, {1, -2}}, -3),
    t({{2},{3,4},{6,5,7},{4,1,8,3}}, 11)
  )
);

TEST_P(P0120_Triangle, Generic) {
  EXPECT_EQ(
      GetParam().second,
      sol.minimumTotal(const_cast<INPUT&>(GetParam().first))
  );
}
