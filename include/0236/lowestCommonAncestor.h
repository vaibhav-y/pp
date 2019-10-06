#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <TreeNode.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Equivalent python3 solution:
//
// # Definition for a binary tree node.
// # class TreeNode:
// #     def __init__(self, x):
// #         self.val = x
// #         self.left = None
// #         self.right = None
//
// class Solution:
//     def lowestCommonAncestor(self,
//                              root: 'TreeNode',
//                              p: 'TreeNode',
//                              q: 'TreeNode') -> 'TreeNode':
//         if not root or not p or not q:
//           return None
//         parent = {root: None}
//         stack = [root]
//         while (p not in parent or q not in parent):
//           node = stack.pop()
//           if (node.left):
//             parent[node.left] = node
//             stack.append(node.left)
//           if (node.right):
//             parent[node.right] = node
//             stack.append(node.right)
//         ancestors = set()
//         while p:
//           ancestors.add(p)
//           p = parent[p]
//
//         while q not in ancestors:
//           q = parent[q]
//         return q

namespace p0236 {
class Solution {
private:
  typedef std::unordered_map<TreeNode *, TreeNode *> ParentMap;

public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
      return nullptr;
    }

    std::vector<TreeNode *> stack{root};
    ParentMap parentMap;
    parentMap[root] = nullptr;

    while (parentMap.find(p) == parentMap.end() ||
           parentMap.find(q) == parentMap.end()) {
      TreeNode *node = stack.back();
      stack.pop_back();
      if (node->left) {
        parentMap[node->left] = node;
        stack.push_back(node->left);
      }
      if (node->right) {
        parentMap[node->right] = node;
        stack.push_back(node->right);
      }
    }

    std::unordered_set<TreeNode *> ancestors;

    while (p) {
      ancestors.insert(p);
      p = parentMap[p];
    }
    while (ancestors.find(q) == ancestors.end()) {
      q = parentMap[q];
    }
    return q;
  }
};
} // namespace p0236
