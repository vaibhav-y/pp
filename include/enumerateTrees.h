#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include "TreeNode.h"
#include <vector>

namespace p0095 {
class Solution {
private:
  std::vector<TreeNode *> generateBST(int root, int lower, int upper) {                                 
    // For fixed root value, try all com
    return std::vector<TreeNode*>();
  }

public:
  std::vector<TreeNode *> generateTrees(int n) {
    std::vector<TreeNode*> roots;
    for (int i = 1; i <= n; ++i) {
      std::vector<TreeNode *> &&nodes = generateBST(i, 1, n);
      roots.reserve(roots.size() + nodes.size());
      roots.insert(std::end(roots), std::begin(nodes), std::end(nodes));
    }
    return roots;
  }
};
} // namespace p0095
