#include <gtest/gtest.h>
#include <utility>
#include <vector>
#include <TreeNode.h>

#include <0515/largestValues.h>

typedef TreeNode *INPUT;
typedef std::vector<int> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;

class P0515_LargestNodeValues : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0515::Solution sol;
};

INSTANTIATE_TEST_CASE_P(FindLevelLargest, P0515_LargestNodeValues,
  ::testing::Values(
    t(Tree("[]"), {}),
    t(Tree("[2,1,3]"), {2, 3}),
    t(Tree("[1,2,3,4,null,5,6,null,null,7]"), {1, 3, 6, 7}),
    t(Tree("[1,2,3,4,null,5,6,null,7,null,null,8]"), {1, 3, 6, 8}),
    t(Tree("[1,2,3,4,null,5,6,null,7,null,8,9,null,null,null,10]"),
      {1, 3, 6, 9, 10})
));

TEST_P(P0515_LargestNodeValues, Generic) {
  EXPECT_EQ(GetParam().second, sol.largestValues(GetParam().first));
}
