#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <TreeNode.h>

namespace p0222 {
class Solution {
public:
  int countNodes(TreeNode *root) {
    // Find the right most node without two children, because `root`
    // represents a complete binary tree:
    // See: https://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees
    if (!root) {
      return 0;
    }
    // There is no special property that allows a faster method
    // not unless we already pre-compute store the depth at each node
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
}
