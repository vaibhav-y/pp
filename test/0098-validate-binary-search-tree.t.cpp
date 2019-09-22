#include <gtest/gtest.h>
#include <utility>

#include "TreeNode.h"
#include "isValidBST.h"

typedef TreeNode* INPUT;
typedef bool OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;


class P0098_ValidateBSTTest : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0098::Solution sol;
};

INSTANTIATE_TEST_CASE_P(ValidateBST,P0098_ValidateBSTTest,
::testing::Values(
  t(Tree("[]"), true),
  t(Tree("[1]"), true),
  t(Tree("[2147483647]"), true),
  t(Tree("[-2147483648, null, 2147483647]"), true),
  t(Tree("[0, -2147483648, 2147483647]"), true),
  t(Tree("[-2147483648, 0, 2147483647]"), false),
  t(Tree("[4,3,5,1,2,6,7]"), false),
  t(Tree("[4,2,6,1,3,5,7]"), true),
  t(Tree("[5,1,4,null,null,3,6]"), false)
));

TEST_P(P0098_ValidateBSTTest, Generic) {
  TreeNode *root = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.isValidBST(root)) << "TreeNode: " <<
    treeNodeToString(root);
  delete root;
}
