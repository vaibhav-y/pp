#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers together
#endif

#include <vector>

#include <TreeNode.h>

namespace p0114 {
class Solution {
public:
  void flatten(TreeNode *root) {
    if (!root) {
      return;
    }
    TreeNode *previous = nullptr;

    std::vector<TreeNode *> stack;
    stack.push_back(root);

    while (!stack.empty()) {

      // Traverse the nodes using a preorder traversal
      root = stack.back();
      stack.pop_back();
      if (root->right) {
        stack.push_back(root->right);
      }
      if (root->left) {
        stack.push_back(root->left);
      }

      // If the previous node is initialized,
      // assign the current node to the right child
      // Move previous forward.
      //
      // This destructive modification is okay because we never add a node
      // back to the stack.
      if (previous) {
        previous->right = root;
        previous->left = nullptr;
      }
      previous = root;
    }
  }
};
}
