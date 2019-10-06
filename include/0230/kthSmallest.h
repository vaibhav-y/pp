#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multple solution headers
#endif

#include <TreeNode.h>

namespace p0230 {
class Solution {
  int countNodes(TreeNode* root) {
    if (!root) {
      return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
public:
  int kthSmallest(TreeNode *root, int k) {
    // This could also be done via an inorder traversal + counter
    // for deeper trees, but I suppose this is fine if we can ge the compiler
    // to generate tail call optimized code
    int leftSize = countNodes(root->left);

    if (k <= leftSize) {
      return kthSmallest(root->left, k);
    } else if (k == leftSize + 1) {
      return root->val;
    } else {
      return kthSmallest(root->right, k - leftSize - 1);
    }
  }
};
}
