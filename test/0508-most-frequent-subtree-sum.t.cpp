#include <gtest/gtest.h>
#include <utility>
#include <vector>

#include <TreeNode.h>

#include <0508/findFrequentTreeSum.h>

typedef TreeNode *INPUT;
typedef std::vector<int> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;


class P0508_MostFrequentSubtreeSum : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0508::Solution sol;
};

INSTANTIATE_TEST_CASE_P(SubtreeSumTest, P0508_MostFrequentSubtreeSum,
  ::testing::Values(
    t(Tree("[]"), {}),
    t(Tree("[5,2,-3]"), {-3,2,4}),
    t(Tree("[5,2,-5]"),{2}),
    t(Tree("[5,2,-3,1,2,3,4,5,6,-1,-2,-3,-3,-4,7,8,-12,-13]"), {-3})
));

TEST_P(P0508_MostFrequentSubtreeSum, Generic) {
  auto input = GetParam().first;
  auto expected = GetParam().second;
  auto output = sol.findFrequentTreeSum(input);

  std::sort(output.begin(), output.end());

  EXPECT_EQ(expected, output);
}
