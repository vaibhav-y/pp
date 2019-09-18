#include <gtest/gtest.h>
#include <utility>

#include <enumerateTrees.h>
#include <TreeNode.h>
#include <ostream>

typedef int INPUT;
typedef std::vector<TreeNode *> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0095_EnumerateTreesTest : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0095::Solution sol;
};

INSTANTIATE_TEST_CASE_P(BSTEnumerationTest, P0095_EnumerateTreesTest,
  ::testing::Values(
    t(1, {stringToTreeNode("[1, null, null]")})
  )
);

std::ostream& operator<<(std::ostream &os, TreeNode* root) {
  os << treeNodeToString(root);
  return os;
}

TEST_P(P0095_EnumerateTreesTest, Generic) {
  std::vector<TreeNode *> output = GetParam().second;
  int input = GetParam().first;
  EXPECT_EQ(output, sol.generateTrees(input));

  for (auto root : output) {
    delete root;
  }
}
