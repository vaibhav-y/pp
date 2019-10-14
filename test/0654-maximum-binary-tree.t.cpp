#include <gtest/gtest.h>
#include <utility>
#include <vector>
#include <TreeNode.h>

#include <0654/constructMaximumBinaryTree.h>

typedef std::vector<int> INPUT;
typedef TreeNode *OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;

class P0654_MaxBinaryTree : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0654::Solution sol;  
};

INSTANTIATE_TEST_CASE_P(MaxBinaryTreeTest, P0654_MaxBinaryTree,
  ::testing::Values(
    t({3,2,1,6,0,5}, Tree("[6,3,5,null,2,0,null,null,1]")),
    t({3,2,1,5,0,6}, Tree("[6,5,null,3,0,null,2,null,null,null,1]"))
));


TEST_P(P0654_MaxBinaryTree, Generic) {
  INPUT input = GetParam().first;
  auto &&output = sol.constructMaximumBinaryTree(input);
  EXPECT_PRED2(TreeEq, GetParam().second, output);
}
