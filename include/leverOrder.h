#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <queue>
#include <vector>

#include "TreeNode.h"

namespace p0102 {
class Solution {
  std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    std::vector<std::vector<int>> levels;
    if (!root) {
      return {};
    }

    std::queue<TreeNode *> parentQ;
    std::queue<TreeNode *> childQ;
    parentQ.push(root);
    while (!parentQ.empty()) {
      levels.push_back({});

      // Save all the children of this level into their own queue
      while(!parentQ.empty()) {
        auto &current = parentQ.front();
        levels.back().push_back(current->val);
        if (current->left) {
          childQ.push(current->left);
        }
        if (current->right) {
          childQ.push(current->right);
        }
        parentQ.pop();
      }

      // At this stage parentQ has been drained and childQ contains the inputs
      // for the next iteration:
      // ParentQ is full, ChildQ is empty
      parentQ.swap(childQ);
    }
    return levels;
  }
};
} // namespace p0102
