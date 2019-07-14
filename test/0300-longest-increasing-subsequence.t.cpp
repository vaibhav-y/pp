#include <gtest/gtest.h>
#include <vector>
#include <utility>

#include "lengthOfLIS.h"

typedef std::vector<int> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0300_LISLength : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0300::Solution sol;
};

INSTANTIATE_TEST_CASE_P(LISLengthTest, P0300_LISLength,
  ::testing::Values(
    t({}, 0),
    t({10}, 1),
    t({2, 2}, 1),
    t({1, 3, 6, 7, 9, 4, 10, 5, 6}, 6),
    t({10, 9, 2, 5, 3, 7, 101, 18}, 4),
    t({15, 27, 14, 38, 26, 55, 46, 65, 85}, 6)
  )
);

TEST_P(P0300_LISLength, Generic) {
  EXPECT_EQ(
    GetParam().second,
    sol.lengthOfLIS(const_cast<INPUT&>(GetParam().first))
  );
}
