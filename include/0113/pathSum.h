#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <vector>
#include <numeric>

#include <TreeNode.h>

namespace p0113 {
class Solution {
private:
  inline bool isLeaf(TreeNode *root) {
    return root->left == nullptr && root->right == nullptr;
  }

  void traverse(TreeNode *root, int target,
                std::vector<int> &current,
                std::vector<std::vector<int>> &paths) {
    if (!root) {
      return;
    }
    // Record visiting this node in the current path if it is valid
    current.push_back(root->val);

    // The comparison is made at the leaf instead of the NULL child because
    // comparing for `target == 0` at the null-leaf results in duplicates
    // because we descend into each of the leaves
    if (target == root->val && isLeaf(root)) {
      paths.push_back(current);
    }

    // Descend Post order
    traverse(root->left, target - root->val, current, paths);
    traverse(root->right, target - root->val, current, paths);

    // Once we are done exploring a subtree, backtrack the path stack
    current.pop_back();
  }
public:
  std::vector<std::vector<int>> pathSum(TreeNode *root, int sum) {
    if (!root) {
      return {};
    }
    std::vector<int> currentPath;
    std::vector<std::vector<int>> paths;
    traverse(root, sum, currentPath, paths);
    return paths;
  }
};
}
