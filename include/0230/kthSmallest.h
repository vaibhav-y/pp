#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multple solution headers
#endif

#include <vector>
#include <limits>

#include <TreeNode.h>

namespace p0230 {
class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    std::vector<TreeNode *> nodeStack;
    while (true) {
      while (root) {
        nodeStack.push_back(root);
        root = root->left;
      }

      if (nodeStack.empty()) {
        break;
      }
      root = nodeStack.back();
      nodeStack.pop_back();
      if (k == 1) {
        return root->val;
      }
      --k;
      root = root->right;
    }
    std::terminate();
  }
};
}
