#include <gtest/gtest.h>
#include <utility>
#include <0876/middleNode.h>

#include <ListNode.h>

typedef ListNode* INPUT;
typedef ListNode* OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;


auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &l = stringToListNode;

class P0876_MiddleNode : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0876::Solution sol;
};

INSTANTIATE_TEST_CASE_P(MiddleNodeTest, P0876_MiddleNode,
  ::testing::Values(
    t(l("[]"), l("[]")),
    t(l("[1]"), l("[1]")),
    t(l("[1,2]"), l("[2]")),
    t(l("[1,2,3,4,5]"), l("[3,4,5]")),
    t(l("[1,2,3,4,5,6]"), l("[4,5,6]"))
  ));

TEST_P(P0876_MiddleNode, Generic) {
  ListNode *input = GetParam().first;
  ListNode *expected = GetParam().second;
  ListNode *output = sol.middleNode(input);

  if (!output) {
    EXPECT_EQ(expected, nullptr);
  } else if (!expected) {
    EXPECT_EQ(nullptr, output);
  } else {
    EXPECT_EQ(*expected, *output);
  }
}
