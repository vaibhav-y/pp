#include <gtest/gtest.h>
#include <utility>
#include <vector>

#include "TreeNode.h"
#include "buildTree.h"


typedef std::pair<std::vector<int>, std::vector<int>> INPUT;
typedef TreeNode* OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;
auto &In = std::make_pair<INPUT::first_type, INPUT::second_type>;

class P0106_ConstructBinaryTree : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0106::Solution sol;
};


INSTANTIATE_TEST_CASE_P(ConstructTree, P0106_ConstructBinaryTree,
  ::testing::Values(
    t(In({}, {}), Tree("[]")),
    t(In({4,5,2,6,7,3,1}, {4,2,5,1,6,3,7}), Tree("[1,2,3,4,5,6,7]")),
    t(In({6,7,3,1}, {1,6,3,7}), Tree("[1,null,3,6,7]")),
    t(In({4,5,2,1}, {4,2,5,1}), Tree("[1,2,null,4,5]")),
    t(In({9,15,7,20,3}, {9,3,15,20,7}), Tree("[3,9,20,null,null,15,7]")),
    t(In({4,5,2,3,1}, {4,2,5,1,3}), Tree("[1,2,3,4,5,null,null]"))

));


TEST_P(P0106_ConstructBinaryTree, Generic) {
  auto &input = GetParam().first;
  auto &expected = GetParam().second;
  auto &postorder = input.first;
  auto &inorder = input.second;
  const auto &output =
      sol.buildTree(const_cast<INPUT::first_type&>(inorder),
                    const_cast<INPUT::second_type&>(postorder));

  if (expected != nullptr && output != nullptr) {
    std::stringstream ss;
    ss << "Expected:\n" << expected << "\n" <<
          "Actual:  \n" << output;
    EXPECT_EQ(*expected, *output) << ss.str();
  }
  else {
    FAIL() <<
    "Expected:\n" << expected << "\n" <<
    "Actual:  \n" << output;
  }
}
