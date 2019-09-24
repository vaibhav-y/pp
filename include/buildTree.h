#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "TreeNode.h"

namespace p0105 {
class Solution {
  typedef std::vector<int>::const_iterator CIT;

  TreeNode *buildTreeRecursive(CIT preOrderFirst, CIT preOrderLast,
                               CIT inOrderFirst, CIT inOrderLast) {

    TreeNode *root = new TreeNode(*preOrderFirst);
    if (std::next(preOrderFirst) == preOrderLast) {
      return root;
    }
    // Pre-order array is structured recursively as follows
    //  [root, ...left, ...right]
    // In-order array is structured as follows:
    // [...left, root, ...right]
    //
    // If we can locate the root known from the pre-order list, we have a
    // recursive work parition ready
    CIT rootLoc = std::find(inOrderFirst, inOrderLast, *preOrderFirst);
    size_t leftSize = std::distance(inOrderFirst, rootLoc);
    size_t rightSize = std::distance(rootLoc, inOrderLast);
    if (leftSize > 0) {
      root->left =
          buildTreeRecursive(preOrderFirst + 1, preOrderFirst + 1 + leftSize,
                             inOrderFirst, rootLoc);
    }
    if (rightSize > 0) {
      root->right = buildTreeRecursive(preOrderFirst + 1 + leftSize,
                                       preOrderLast, rootLoc + 1, inOrderLast);
    }
    return root;
  }

public:
  TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
    // These two must have the same size, so check only one of them
    if (preorder.empty()) {
      return nullptr;
    }
    return buildTreeRecursive(preorder.begin(), preorder.end(), inorder.begin(),
                              inorder.end());
  }
};
} // namespace p0105
