#include <gtest/gtest.h>
#include <utility>
#include <vector>

#include "TreeNode.h"

typedef TreeNode* INPUT;
typedef std::vector<std::vector<int>> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;

class P0102_LevelOrderTraversal : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0102::Solution sol;
};

INSTANTIATE_TEST_CASE_P(LevelOrderTraversalTest, P0102_LevelOrderTraversal,
  ::testing::Values(
    t(Tree("[]"), {})
));

TEST_P(P0102_LevelOrderTraversal, Generic) {
  TreeNode* root = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.levelOrder(root));
  delete root;
}
