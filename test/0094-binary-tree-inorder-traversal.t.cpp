#include <gtest/gtest.h>
#include <utility>
#include <vector>

#include <TreeNode.h>
#include <inorderTraversal.h>

typedef TreeNode* INPUT;
typedef std::vector<int> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;

class P0094_InorderTraversal : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0094::Solution sol;
};

INSTANTIATE_TEST_CASE_P(InorderTraversal, P0094_InorderTraversal,
  ::testing::Values(
    t(stringToTreeNode("[]"), {}),
    t(stringToTreeNode("[1,null,2,3]"), {1,3,2}),
    t(stringToTreeNode("[1,2,3,4,5,null,6,null,null,7,8]"), {4,2,7,5,8,1,3,6})
  )
);

TEST_P(P0094_InorderTraversal, Generic) {
  TreeNode *root = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.inorderTraversal(root));
  delete root;
}
