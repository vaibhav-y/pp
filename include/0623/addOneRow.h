#ifndef INCLUDED_SOLUTION_HEADER
#define INCLUDED_SOLUTION_HEADER

#include <TreeNode.h>
#include <queue>

namespace p0623 {
class Solution {
public:
  TreeNode *addOneRow(TreeNode *root, int value, int depth) {
    if (!root) {
      return nullptr;
    }
    if (depth == 1) {
      TreeNode *t = new TreeNode(value);
      t->left = root;
      return t;
    }
    std::queue<std::pair<int, TreeNode *>> parentQ;
    parentQ.emplace(1, root);
    while (!parentQ.empty()) {
      int currentDepth;
      TreeNode *currentNode;
      std::tie(currentDepth, currentNode) = parentQ.front();
      parentQ.pop();
      if (currentDepth + 1 == depth) {
        TreeNode *temp = currentNode->left;
        currentNode->left = new TreeNode(value);
        currentNode->left->left = temp;

        temp = currentNode->right;
        currentNode->right = new TreeNode(value);
        currentNode->right->right = temp;
      }
      if (currentDepth == depth) {
        return root;
      }
      if (currentNode->left) {
        parentQ.emplace(currentDepth + 1, currentNode->left);
      }
      if (currentNode->right) {
        parentQ.emplace(currentDepth + 1, currentNode->right);
      }
    }
    return root;
  }
};
} // namespace p0623

#endif
