#include <gtest/gtest.h>
#include <utility>
#include <vector>

#include <0652/findDuplicateSubtrees.h>

typedef TreeNode *INPUT;
typedef std::vector<TreeNode *> OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;

class P0652_FindDuplicateSubtrees : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0652::Solution sol;
};

INSTANTIATE_TEST_CASE_P(DupSubtrees, P0652_FindDuplicateSubtrees,
  ::testing::Values(
    t(Tree("[]"), {}),
    t(Tree("[1,2,3,4,null,2,4,null,null,4]"), {Tree("[4]"), Tree("[2,4,null]")}),
    t(Tree("[0,0,0,0,null,null,0,null,null,null,0]"), {Tree("[0]")})
));


TEST_P(P0652_FindDuplicateSubtrees, Generic) {
  auto &&output = sol.findDuplicateSubtrees(GetParam().first);
  auto &&expected = GetParam().second;

  ASSERT_EQ(expected.size(), output.size());

  for (size_t i = 0; i < expected.size(); ++i) {
    ASSERT_PRED2(TreeEq, expected[i], output[i]);
  }
}
