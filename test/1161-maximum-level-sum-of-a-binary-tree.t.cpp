#include <gtest/gtest.h>
#include <utility>
#include <1161/maxLevelSum.h>

#include <TreeNode.h>

typedef TreeNode *INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;

class P1161_MaxLevelSum : public ::testing::TestWithParam<TESTCASE> {
protected:
  p1161::Solution sol;
};

INSTANTIATE_TEST_CASE_P(MaxLevelSumTest, P1161_MaxLevelSum,
  ::testing::Values(
    t(Tree("[]"), 0),
    t(Tree("[20]"), 1),
    t(Tree("[1,7,0,7,-8,null,null]"), 2)
));

TEST_P(P1161_MaxLevelSum, Generic) {
  EXPECT_EQ(GetParam().second, sol.maxLevelSum(GetParam().first));
}
