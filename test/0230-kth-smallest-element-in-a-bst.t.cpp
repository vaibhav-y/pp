#include <gtest/gtest.h>
#include <utility>

#include <0230/kthSmallest.h>

typedef std::pair<TreeNode *, int> INPUT;
typedef int OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;


class P0230_KthSmallest : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0230::Solution sol;
};

INSTANTIATE_TEST_CASE_P(KthSmallestTreeNode, P0230_KthSmallest,
  ::testing::Values(
    t({Tree("[3,1,4,null,2]"), 1}, 1),
    t({Tree("[5,3,6,2,4,null,null,1]"), 3}, 3),
    t({Tree("[5,1]"), 1}, 1),
    t({Tree("[5,3,6,2,4,null,null,1]"), 1}, 1),
    t({Tree("[5,3,6,2,4,null,null,1]"), 2}, 2),
    t({Tree("[5,3,6,2,4,null,null,1]"), 3}, 3),
    t({Tree("[5,3,6,2,4,null,null,1]"), 4}, 4),
    t({Tree("[5,3,6,2,4,null,null,1]"), 5}, 5),
    t({Tree("[5,3,6,2,4,null,null,1]"), 6}, 6)
));

TEST_P(P0230_KthSmallest, Generic) {
  auto params = GetParam().first;
  EXPECT_EQ(GetParam().second, sol.kthSmallest(params.first, params.second));
}
