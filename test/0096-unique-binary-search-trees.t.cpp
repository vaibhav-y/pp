#include <gtest/gtest.h>
#include <utility>

#include "numTrees.h"

typedef int INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0096_NumTress : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0096::Solution sol;
};

INSTANTIATE_TEST_CASE_P(NumTreesTest, P0096_NumTress,
  ::testing::Values(
    t(0, 1),
    t(1, 1),
    t(2, 2),
    t(3, 5),
    t(4, 14),
    t(5, 42),
    t(6, 132),
    t(7, 429),
    t(8, 1430),
    t(9, 4862),
    // This is the largest number
    t(19, 1767263190)
  )
);

TEST_P(P0096_NumTress, Generic) {
  EXPECT_EQ(
    GetParam().second,
    sol.numTrees(GetParam().first)
  );
}
