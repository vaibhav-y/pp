#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <stack>
#include <utility>
#include <TreeNode.h>
#include <cassert>

namespace p0513 {
class Solution {
public:
  int findBottomLeftValue(TreeNode *root) {
    assert(root != nullptr);

    std::stack<std::pair<TreeNode *, int>> depthStack;
    depthStack.push({root, 0});
    int maxDepth = 0;
    int deepestVal = root->val;

    while (!depthStack.empty()) {
      int depth;
      std::tie(root, depth) = depthStack.top();
      depthStack.pop();

      if (depth > maxDepth) {
        maxDepth = depth;
        deepestVal = root->val;
      }
      if (root->right) {
        depthStack.push({root->right, depth + 1});
      }
      if (root->left) {
        depthStack.push({root->left, depth + 1});
      }
    }
    return deepestVal;
  }
};
}
