#include <gtest/gtest.h>
#include <utility>
#include <TreeNode.h>

#include <0701/insertIntoBST.h>

typedef std::pair<TreeNode *, int> INPUT;
typedef TreeNode *OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;

class P0701_BSTInsertionTest : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0701::Solution sol;
};

INSTANTIATE_TEST_CASE_P(BSTInsertionTest, P0701_BSTInsertionTest,
  ::testing::Values(
    t({Tree("[]"), 1}, Tree("[1]")),
    t({Tree("[6]"), 5}, Tree("[6, 5]")),
    t({Tree("[4,2,7,1,3]"), 5}, Tree("[4,2,7,1,3,5]"))
));

TEST_P(P0701_BSTInsertionTest, Generic) {
  auto expected = GetParam().second;
  auto output = sol.insertIntoBST(GetParam().first.first,
                                  GetParam().first.second);
  EXPECT_EQ(*expected, *output);
}
