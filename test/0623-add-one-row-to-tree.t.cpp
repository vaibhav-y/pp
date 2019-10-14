#include <gtest/gtest.h>
#include <tuple>
#include <TreeNode.h>

#include <0623/addOneRow.h>

typedef std::tuple<TreeNode *, int, int> INPUT;
typedef TreeNode *OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;

class P0623_AddRowToTree : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0623::Solution sol;
};

INSTANTIATE_TEST_CASE_P(AddRowTest, P0623_AddRowToTree, ::testing::Values(
  t({Tree("[]"), 1, 1}, Tree("[]")),
  t({Tree("[4,2,6,3,1,5]"), 1, 2}, Tree("[4,1,1,2,null,null,6,3,1,5]")),
  t({Tree("[4,2,null,3,1]"), 1, 3}, Tree("[4,2,null,1,1,3,null,null,1]")),
  t({Tree("[1,2,3,4]"), 5, 4}, Tree("[1,2,3,4,null,null,null,5,5]")),
  t({Tree("[1,2,3,4]"), 5, 1}, Tree("[5,1,null,2,3,4]")),
  t({Tree("[4,2,6,3,1,5]"), 1, 3}, Tree("[4,2,6,1,1,1,1,3,null,null,1,5]"))
));

TEST_P(P0623_AddRowToTree, Generic) {
  TreeNode *root;
  int value, depth;
  std::tie(root, value, depth) = GetParam().first;
  auto &&output = sol.addOneRow(root, value, depth);
  EXPECT_PRED2(TreeEq, GetParam().second, output);
}
