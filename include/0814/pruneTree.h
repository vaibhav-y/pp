#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <TreeNode.h>

namespace p0814 {
class Solution {
private:
  void freeTree(TreeNode *root) {
    if (!root) {
      return;
    }
    freeTree(root->left);
    freeTree(root->right);
    delete root;
  }

  int sumAndFree(TreeNode *root) {
    if (!root) {
      return 0;
    }
    root->val += sumAndFree(root->left) + sumAndFree(root->right);
    if (root->left && root->left->val == 0) {
      freeTree(root->left);
      root->left = nullptr;
    }
    if (root->right && root->right->val == 0) {
      freeTree(root->right);
      root->right = nullptr;
    }
    return root->val;
  }

  void restore(TreeNode *root) {
    if (!root) {
      return;
    }
    if (!root->left && !root->right) {
      return;
    }
    if (root->left) {
      root->val -= root->left->val;
    }
    if (root->right) {
      root->val -= root->right->val;
    }
    restore(root->left);
    restore(root->right);
  }

public:
  TreeNode *pruneTree(TreeNode *root) {
    // First sum up all the nodes in the subtree
    sumAndFree(root);
    restore(root);
    return root;
  }
};
} // namespace p0814
