#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <iostream>
#include <vector>
#include "TreeNode.h"

namespace p0098 {
class Solution {
  static constexpr size_t MAGIC_DEPTH_GUESS = 32;
public:
  bool isValidBST(TreeNode *root) {
    std::vector<TreeNode *> stack;
    stack.reserve(MAGIC_DEPTH_GUESS);

    TreeNode *previous = nullptr;

    while (true) {
      while(root) {
        stack.push_back(root);
        root = root->left;
      }
      if (stack.empty()) {
        break;
      }
      root = stack.back();
      if (!previous) {
        previous = root;
      }
      else if (root->val > previous->val) {
        previous = root;
      } else {
        return false;
      }
      stack.pop_back();
      root = root->right;
    }
    return true;
  }
};
} // namespace p0094
