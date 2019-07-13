#include <gtest/gtest.h>
#include <utility>
#include <vector>

typedef std::pair<std::vector<int> , int> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

#include "coinChange.h"

auto &t = std::make_pair<INPUT, OUTPUT>;
auto &i = std::make_pair<INPUT::first_type, INPUT::second_type>;

class P0322_CoinChange : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0322::Solution sol;
};

INSTANTIATE_TEST_CASE_P(CoinChangeTest, P0322_CoinChange,
  ::testing::Values(
    t(i({}, 1), -1),
    t(i({2}, 3), -1),
    t(i({1, 2, 5}, 8), 3),
    t(i({1, 2, 5}, 11), 3)
  )
);

TEST_P(P0322_CoinChange, Generic) {
  auto &input = GetParam().first;
  auto &output = GetParam().second;

  EXPECT_EQ(
      output,
      sol.coinChange(
        const_cast<INPUT::first_type&>(input.first),
        input.second
      )
  );
}
