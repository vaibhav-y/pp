#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <queue>
#include <utility>
#include <iostream>
#include <TreeNode.h>

namespace p1161 {
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  int maxLevelSum(TreeNode* root) {
    if (!root) {
      return 0;
    }
    std::queue<std::pair<int, TreeNode *>> nodeQ;
    nodeQ.push({1, root});
    int maxLevel = 0;
    int maxLevelSum = std::numeric_limits<int>::min();

    while (!nodeQ.empty()) {
      int level;
      TreeNode *node;
      std::tie(level, node) = nodeQ.front();
      int levelSum = 0;

      // Extract all nodes with the given level, and sum them up
      while (level == nodeQ.front().first) {
        std::tie(level, node) = nodeQ.front();
        levelSum += node->val;
        nodeQ.pop();

        if (node->left) {
          nodeQ.push({level + 1, node->left});
        }
        if (node->right) {
          nodeQ.push({level + 1, node->right});
        }
      }

      // nodeQ.front() is the first element of the next level now
      if (levelSum > maxLevelSum) {
        maxLevel = level;
        maxLevelSum = levelSum;
      }
    }

    return maxLevel;
  }
};
}
