#include <gtest/gtest.h>
#include <utility>
#include <string>
#include <vector>

#include "shiftingLetters.h"

typedef std::pair<std::string, std::vector<int>> INPUT;
typedef std::string OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<INPUT, OUTPUT>;

class P0848_ShiftingLetters : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0848::Solution sol;
};

INSTANTIATE_TEST_CASE_P(ShiftingLettersTest, P0848_ShiftingLetters,
  ::testing::Values(
    t({"", {}}, ""),
    t({"abc", {3, 5, 9}}, "rpl")
  )
);

TEST_P(P0848_ShiftingLetters, Generic) {
  auto input = GetParam().first;
  auto expected = GetParam().second;

  EXPECT_EQ(expected, sol.shiftingLetters(input.first, input.second));
}
