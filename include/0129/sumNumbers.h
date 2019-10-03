#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include mulitple solution headers
#endif

#include <vector>
#include <utility>

#include <TreeNode.h>

namespace p0129 {
class Solution {
private:
  inline bool isLeaf(TreeNode *root) {
    return root->left == nullptr && root->right == nullptr;
  }
  int sumNumbers(TreeNode *root, int acc) {
    if (isLeaf(root)) {
      return 10 * acc + root->val;
    }
    int sumLeft = 0;
    int sumRight = 0;
    if (root->left) {
      sumLeft += sumNumbers(root->left, 10 * acc + root->val);
    }
    if (root->right) {
      sumRight += sumNumbers(root->right, 10 * acc + root->val);
    }
    return sumLeft + sumRight;
  }
public:
  int sumNumbers(TreeNode *root) {
    if (!root) {
      return 0;
    }
    int sum = 0;
    std::vector<std::pair<TreeNode *, int>> stack;
    stack.push_back({root, 0});

    while (!stack.empty()) {
      int acc;
      std::tie(root, acc) = stack.back();
      stack.pop_back();
      if (isLeaf(root)) {
        sum += 10 * acc + root->val;
      }
      if (root->right) {
        stack.push_back({root->right, 10 * acc + root->val});
      }
      if (root->left) {
        stack.push_back({root->left, 10 * acc + root->val});
      }
    }

    return sum;
  }
};
}
