#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solutions headers
#endif

#include <TreeNode.h>
#include <vector>

namespace p0094 {
class Solution {
static constexpr size_t MAGIC_MAX_DEPTH_GUESS = 32;
public:
  std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<TreeNode*> stack;
    stack.reserve(MAGIC_MAX_DEPTH_GUESS);
    std::vector<int> nodeValues;

    while (true) {
      while (root) {
        stack.push_back(root);
        root = root->left;
      }
      if (stack.empty()) {
        break;
      }

      root = stack.back();
      nodeValues.push_back(root ->val);
      stack.pop_back();

      // Force it to descend into the right subtree, if applicable
      root = root->right;
    }
    return nodeValues;
  }
};
} // namespace p0094
