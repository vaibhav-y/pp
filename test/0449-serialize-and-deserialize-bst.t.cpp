#include <TreeNode.h>
#include <gtest/gtest.h>
#include <utility>

#include <treeCodecBreadthFirst.h>

typedef TreeNode *INPUT;
typedef TreeNode *OUTPUT;
typedef std::pair<INPUT, OUTPUT> TESTCASE;

auto &t = std::make_pair<TESTCASE::first_type, TESTCASE::second_type>;
auto &Tree = stringToTreeNode;

class P0449_SerDeTree : public ::testing::TestWithParam<TESTCASE> {
protected:
  p0449::bfs::Codec bfsCodec;
};

INSTANTIATE_TEST_CASE_P(
    SerdeTest, P0449_SerDeTree,
    ::testing::Values(
        t(Tree("[1,null,2,null,3,null,4,null,5,null,6,null,7,null]"),
          Tree("[1,null,2,null,3,null,4,null,5,null,6,null,7,null]")),
        t(Tree("[1,null,2]"), Tree("[1,null,2]")),
        t(Tree("[2,1,3]"), Tree("[2,1,3]")),
        t(Tree("[5,3,6,2,4,null,null,1]"), Tree("[5,3,6,2,4,null,null,1]")),
        t(Tree("[5,3,6,2,4,1]"), Tree("[5,3,6,2,4,1]"))));


TEST_P(P0449_SerDeTree, BreadthFirstTraversal) {
  TreeNode *expected = GetParam().second;
  TreeNode *serde = bfsCodec.deserialize(bfsCodec.serialize(GetParam().first));
  EXPECT_PRED2(TreeEq, expected, serde);
}

// TEST_P(P0449_SerDeTree, PreOrderTraversal) {
//   EXPECT_PRED2(TreeEq, GetParam().second,
//   bfs::Codec::deserialize(bfs::Codec::serialize(GetParam().first)));
// }
