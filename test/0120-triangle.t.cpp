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

INSTANTIATE_TEST_CASE_P(TriagleMinPathTest, P0120_Triangle, 
  ::testing::Values(
    t({}, 0)
  )
);

TEST_P(P0120_Triangle, Generic) {
  EXPECT_EQ(GetParam().second, sol.minimumTotal(GetParam().first));
}
