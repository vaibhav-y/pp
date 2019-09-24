#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <unordered_map>

#include "TreeNode.h"

namespace p0105 {
class Solution {
  typedef std::vector<int>::const_iterator CIT;
  typedef std::unordered_map<int, CIT> RootMap;

  TreeNode *buildTree(CIT preOrderFirst, CIT preOrderLast, CIT inOrderFirst,
                      CIT inOrderLast, const RootMap &roots) {
    if (preOrderFirst == preOrderLast) {
      return nullptr;
    } else if (std::next(preOrderFirst) == preOrderLast) {
      return new TreeNode(*preOrderFirst);
    }
    TreeNode *root = new TreeNode(*preOrderFirst);
    // Pre-order array is structured recursively as follows
    //  [root, ...left, ...right]
    // In-order array is structured as follows:
    // [...left, root, ...right]
    //
    // If we can locate the root known from the pre-order list, we have a
    // recursive work parition ready
    CIT rootLoc = roots.at(root->val);
    size_t leftSize = std::distance(inOrderFirst, rootLoc);
    size_t rightSize = std::distance(rootLoc, inOrderLast);
    if (leftSize > 0) {
      root->left = buildTree(preOrderFirst + 1, preOrderFirst + 1 + leftSize,
                             inOrderFirst, rootLoc, roots);
    }
    if (rightSize > 0) {
      root->right = buildTree(preOrderFirst + 1 + leftSize, preOrderLast,
                              rootLoc + 1, inOrderLast, roots);
    }
    return root;
  }

public:
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    // These two must have the same size, so check only one of them
    if (preorder.empty()) {
      return nullptr;
    }
    RootMap m;
    // Doesn't deal with duplicates, but those are easily addressed by changing
    // the value_type to a vector (to treat as a stack)
    for (CIT c = inorder.begin(); c != inorder.end(); ++c) {
      m[*c] = c;
    }
    return buildTree(preorder.begin(), preorder.end(), inorder.begin(),
                     inorder.end(), m);
  }
};
} // namespace p0105
