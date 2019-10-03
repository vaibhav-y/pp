#include <gtest/gtest.h>
#include <utility>

#include <TreeNode.h>
#include <sumNumbers.h>

typedef TreeNode *INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &Tree = stringToTreeNode;
auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0129_SumRootToLeafPaths : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0129::Solution sol;
};

INSTANTIATE_TEST_CASE_P(SumRootToLeaf, P0129_SumRootToLeafPaths,
  ::testing::Values(
    t(Tree("[]"), 0),
    t(Tree("[1,2,3]"), 25),
    t(Tree("[4,9,0,5,1]"), 1026)
));

TEST_P(P0129_SumRootToLeafPaths, Generic) {
  auto &input = GetParam().first;
  auto &output = GetParam().second;

  EXPECT_EQ(output, sol.sumNumbers(input));
}
