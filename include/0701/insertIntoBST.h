#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <TreeNode.h>

namespace p0701 {
class Solution {
public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root) {
      TreeNode *current = root, *parent = nullptr;
      while (current) {
        if (val > current->val) {
          parent = current;
          current = current->right;
        } else {
          parent = current;
          current = current->left;
        }
      }
      // 'parent' is the insertion hint
      if (val > parent->val) {
        parent->right = new TreeNode(val);
      } else {
        parent->left = new TreeNode(val);
      }
    } else {
      root = new TreeNode(val);
    }
    return root;
  }
};
} // namespace p0701
