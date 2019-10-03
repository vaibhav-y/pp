#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont included multiple solution headers
#endif

#include <vector>

#include <TreeNode.h>

namespace p0144 {
class Solution {
public:
  std::vector<int> preorderTraversal(TreeNode *root) {
    if (!root) {
      return {};
    }
    std::vector<int> nodes;
    std::vector<TreeNode *> stack;
    stack.push_back(root);
    while (!stack.empty()) {
      root = stack.back();
      stack.pop_back();
      nodes.push_back(root->val);
      if (root->right) {
        stack.push_back(root->right);
      }
      if (root->left) {
        stack.push_back(root->left);
      }
    }
    return nodes;
  }
};
}
