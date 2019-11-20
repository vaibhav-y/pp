#include <gtest/gtest.h>
#include <utility>
#include <0310/findMinHeightTrees.h>

#include <vector>

typedef std::pair<int, std::vector<std::vector<int>>> INPUT;
typedef std::vector<int> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0310_FindMinHeightTrees : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0310::Solution sol;
};

INSTANTIATE_TEST_CASE_P(FindMinHeightTreesTest, P0310_FindMinHeightTrees,
  ::testing::Values(
    t({4, {{0,1},{1,2},{1,3}}}, {1}),
    t({6, {{0,3},{1,3},{2,3},{4,3},{5,4}}}, {3,4})
));

TEST_P(P0310_FindMinHeightTrees, Generic) {
  auto input = GetParam().first;
  auto expected = GetParam().second;

  EXPECT_EQ(expected,
            sol.findMinHeightTrees(input.first, input.second));
}
