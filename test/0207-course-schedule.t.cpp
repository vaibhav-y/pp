#include <gtest/gtest.h>
#include <utility>
#include <0207/canFinish.h>

#include <vector>

typedef std::pair<int, std::vector<std::vector<int>>> INPUT;
typedef bool OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0207_CanFinish : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0207::Solution sol;
};

INSTANTIATE_TEST_CASE_P(CanFinishTest, P0207_CanFinish,
  ::testing::Values(
    t({2, {{0,1}}}, true),
    t({2, {{1,0},{0,1}}}, false),
    t({3, {{1,2},{2,0},{1,0}}}, true),
    t({3, {{1,2},{2,0},{1,0}, {2,1}}}, false),
    t({4, {{3,1},{1,2},{2,0},{1,0}, {2,1}}}, false),
    t({8, {{1,0},{2,6},{1,7},{5,1},{6,4},{7,0},{0,5}}}, false)
));

TEST_P(P0207_CanFinish, Generic) {
  auto input = GetParam().first;
  auto expected = GetParam().second;

  EXPECT_EQ(expected, sol.canFinish(input.first, input.second));
}
