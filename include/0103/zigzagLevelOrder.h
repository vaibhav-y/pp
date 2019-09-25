#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include solution header
#endif

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

#include "TreeNode.h"

namespace p0103 {
class Solution {
public:
  std::vector<std::vector<int>> zigzagLevelOrder(TreeNode *root) {
    if (!root) {
      return {};
    }

    std::vector<std::vector<int>> levels;
    std::queue<TreeNode *> parentQ;
    std::queue<TreeNode *> childQ;
    parentQ.push(root);

    bool rightToLeft = false;

    while (!parentQ.empty()) {
      levels.push_back({});
      levels.back().reserve(parentQ.size());

      while (!parentQ.empty()) {
        const auto &current = parentQ.front();
        levels.back().push_back(current->val);
        if (current->left) {
          childQ.push(current->left);
        }
        if (current->right) {
          childQ.push(current->right);
        }
        parentQ.pop();
      }
      if (rightToLeft) {
        std::reverse(levels.back().begin(), levels.back().end());
      }
      rightToLeft = !rightToLeft;
      parentQ.swap(childQ);
    }
    return levels;
  }
};
} // namespace p0103
