#include <gtest/gtest.h>
#include <utility>
#include <vector>

#include <TreeNode.h>

#include <rightSideView.h>

typedef TreeNode *INPUT;
typedef std::vector<int> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;


class P0199_BTreeRightSideView : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0199::Solution sol;
};

INSTANTIATE_TEST_CASE_P(RHSView, P0199_BTreeRightSideView,
  ::testing::Values(
    t(Tree("[]"), {}),
    t(Tree("[1]"), {1}),
    t(Tree("[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]"), {1,3,6,11}),
    t(Tree("[1,2,null,3,null,4,null,5,null]"), {1,2,3,4,5}),
    t(Tree("[1,2,3,4]"), {1,3,4})
));
