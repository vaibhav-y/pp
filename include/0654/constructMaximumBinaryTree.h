#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <TreeNode.h>
#include <vector>
#include <iterator>
#include <algorithm>

namespace p0654 {
class Solution {
private:
  typedef std::vector<int>::const_iterator CIT;

  TreeNode *constructMaximumBinaryTree(CIT first, CIT last) {
    if (std::distance(first, last) == 0) {
      return nullptr;
    }
    auto it = std::max_element(first, last);

    TreeNode *node = new TreeNode(*it);
    if (it == first) {
      // Everything goes to the right
      node->right = constructMaximumBinaryTree(std::next(it), last);
    } else if (it == std::prev(last)) {
      // Everything goes to the left
      node->left = constructMaximumBinaryTree(first, it);
    } else {
      node->left = constructMaximumBinaryTree(first, it);
      node->right = constructMaximumBinaryTree(std::next(it), last);
    }
    return node;
  }
public:
  TreeNode *constructMaximumBinaryTree(std::vector<int> &nums) {
    return constructMaximumBinaryTree(nums.begin(), nums.end());
  }
};
} // namespace p0654

