#include <gtest/gtest.h>
#include <utility>

#include <TreeNode.h>
#include <countNodes.h>

typedef TreeNode *INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;


class P0222_CountNodes : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0222::Solution sol;
};

INSTANTIATE_TEST_CASE_P(CountNodesTest, P0222_CountNodes,
  ::testing::Values(
    t(Tree("[]"), 0),
    t(Tree("[2]"), 1),
    t(Tree("[1,2]"),2),
    t(Tree("[1,2,3]"),3),
    t(Tree("[1,2,3,4,5,6]"), 6)
));
