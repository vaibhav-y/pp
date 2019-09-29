#include <gtest/gtest.h>
#include <utility>
#include <vector>

#include <TreeNode.h>
#include <pathSum.h>

typedef std::pair<TreeNode *, int> INPUT;
typedef std::vector<std::vector<int>> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;
auto &In = std::make_pair<INPUT::first_type, INPUT::second_type>;


class P0113_PathSum : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0113::Solution sol;
};


INSTANTIATE_TEST_CASE_P(PathSumTest, P0113_PathSum,
  ::testing::Values(
    t(In(Tree("[]"), 1), {}),
    t(In(Tree("[1]"), 1), {{1}}),
    t(In(Tree("[5,4,8,11,null,13,4,7,2,null,null,5,1]"), 22), {{5,4,11,2},{5,8,4,5}}),
    t(In(Tree("[1,-2,-3,1,3,-2,null,-1]"), 3), {})
));

TEST_P(P0113_PathSum, Generic) {
  auto &input = GetParam().first;
  auto &expected = GetParam().second;
  auto output = sol.pathSum(input.first, input.second);

  EXPECT_EQ(expected, output);

  delete input.first;
}
