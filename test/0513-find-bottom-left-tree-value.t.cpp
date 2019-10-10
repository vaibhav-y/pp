#include <gtest/gtest.h>
#include <utility>
#include <TreeNode.h>

#include <0513/findBottomLeftValue.h>

typedef TreeNode *INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;

class P0513_BottomLeftNodeValue : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0513::Solution sol;
};

INSTANTIATE_TEST_CASE_P(BottomLeftValueFind, P0513_BottomLeftNodeValue,
  ::testing::Values(
    t(Tree("[2,1,3]"), 1),
    t(Tree("[1,2,3,4,null,5,6,null,null,7]"), 7),
    t(Tree("[1,2,3,4,null,5,6,null,7,null,null,8]"), 7),
    t(Tree("[1,2,3,4,null,5,6,null,null,null,null,null,7]"), 7),
    t(Tree("[1,2,3,4,null,5,6,null,7,null,8,9,null,null,null,10]"), 10)
));

TEST_P(P0513_BottomLeftNodeValue, Generic) {
  EXPECT_EQ(GetParam().second, sol.findBottomLeftValue(GetParam().first));
}
