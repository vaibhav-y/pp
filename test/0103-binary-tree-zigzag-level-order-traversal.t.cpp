#include <gtest/gtest.h>
#include <utility>
#include <vector>

#include "TreeNode.h"
#include "zigzagLevelOrder.h"


typedef TreeNode* INPUT;
typedef std::vector<std::vector<int>> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;

class P0103_LevelOrderTraversal : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0103::Solution sol;
};

INSTANTIATE_TEST_CASE_P(LevelOrderTraversalTest, P0103_LevelOrderTraversal,
  ::testing::Values(
    t(Tree("[]"), {}),
    t(Tree("[4,2,6,1,null,null,7]"), {{4}, {6, 2}, {1, 7}}),
    t(Tree("[4,3,5,1,2,6,7]"), {{4}, {5, 3}, {1, 2, 6, 7}}),
    t(Tree("[3,9,20,null,null,15,7]"), {{3}, {20, 9}, {15, 7}}),
    t(Tree("[1,null,2,null,3,null,4,null,5]"), {{1}, {2}, {3}, {4}, {5}})
));

TEST_P(P0103_LevelOrderTraversal, Generic) {
  TreeNode* root = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.zigzagLevelOrder(root));
  delete root;
}
