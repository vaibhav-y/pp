#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <stack>
#include <utility>
#include <tuple>
#include <vector>
#include <TreeNode.h>

namespace p0515 {
class Solution {
public:
  std::vector<int> largestValues(TreeNode *root) {
    std::vector<int> maximas;

    if (root) {
      std::stack<std::pair<TreeNode *, size_t>> depthStack;
      depthStack.push({root, 0});

      while (!depthStack.empty()) {
        size_t depth;
        std::tie(root, depth) = depthStack.top();
        depthStack.pop();

        if (depth < maximas.size()) {
          maximas[depth] = std::max(maximas[depth], root->val);
        } else {
          maximas.push_back(root->val);
        }

        if (root->right) {
          depthStack.push({root->right, depth + 1});
        }
        if (root->left) {
          depthStack.push({root->left, depth + 1});
        }
      }
    }
    return maximas;
  }
};
}
