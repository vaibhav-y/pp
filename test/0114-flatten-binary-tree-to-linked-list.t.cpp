#include <gtest/gtest.h>
#include <utility>

#include <TreeNode.h>
#include <flatten.h>


typedef TreeNode* INPUT;
typedef TreeNode* OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;

class P0114_FlattenTree : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0114::Solution sol;
};

INSTANTIATE_TEST_CASE_P(Flatten, P0114_FlattenTree, ::testing::Values(
  t(Tree("[]"), Tree("[]")),
  t(Tree("[1]"), Tree("[1]")),
  t(Tree("[1,2,null]"), Tree("[1,null,2]")),
  t(Tree("[1,null,2]"), Tree("[1,null,2]")),
  t(Tree("[1,2,5,3,4,null,6]"),
    Tree("[1,null,2,null,3,null,4,null,5,null,6]")),
  t(Tree("[1,2,5,3,4,6,7]"),
    Tree("[1,null,2,null,3,null,4,null,5,null,6,null,7]"))
));

TEST_P(P0114_FlattenTree, Generic) {
  auto params = GetParam();
  auto tree = params.first;
  auto expected = params.second;
  sol.flatten(tree);
  EXPECT_PRED2(TreeEq, expected, tree);
}
