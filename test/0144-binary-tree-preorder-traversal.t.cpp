#include <gtest/gtest.h>
#include <utility>
#include <vector>

#include <TreeNode.h>
#include <preorderTraversal.h>

typedef TreeNode *INPUT;
typedef std::vector<int> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;

class P0144_PreOrderTraversal : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0144::Solution sol;
};

INSTANTIATE_TEST_CASE_P(PreOrderTraversalTest, P0144_PreOrderTraversal,
  ::testing::Values(
    t(Tree("[]"), {}),
    t(Tree("[1]"), {1}),
    t(Tree("[1,null,2,3]"), {1,2,3})
));

TEST_P(P0144_PreOrderTraversal, Generic) {
  auto &params = GetParam();
  EXPECT_EQ(params.second, sol.preorderTraversal(params.first));
}
