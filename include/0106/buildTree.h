#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <iterator>
#include <unordered_map>
#include <vector>

#include "TreeNode.h"

namespace p0106 {
class Solution {
  typedef std::vector<int>::const_iterator CIT;
  typedef std::unordered_map<int, CIT> RootMap;

  // Convenience struct to have a sane number of parameters
  // Also, clean code
  struct Range {
    CIT first;
    CIT last;
  };

  TreeNode *buildTree(const Range &inorderRange, const Range &postorderRange,
                      RootMap rootLocs) {
    if (postorderRange.first == postorderRange.last) {
      return nullptr;
    } else if (std::next(postorderRange.first) == postorderRange.last) {
      return new TreeNode(*postorderRange.first);
    }
    // The one thing we know is that the last element in the postorder range
    // is the root for the subtree in question
    TreeNode *root = new TreeNode(*std::prev(postorderRange.last));
    const auto &rootLoc = rootLocs.at(root->val);
    // Count of elements in the left, right subtrees respectively
    auto leftSize = std::distance(inorderRange.first, rootLoc);
    auto rightSize = std::distance(std::next(rootLoc), inorderRange.last);
    if (leftSize > 0) {
      root->left = buildTree(
          {inorderRange.first, rootLoc},
          {postorderRange.first, postorderRange.first + leftSize}, rootLocs);
    }
    if (rightSize > 0) {
      root->right = buildTree(
          {std::next(rootLoc), inorderRange.last},
          {postorderRange.first + leftSize, std::prev(postorderRange.last)},
          rootLocs);
    }
    return root;
  }

public:
  TreeNode *buildTree(std::vector<int> &inorder, std::vector<int> &postorder) {
    if (postorder.empty()) {
      return nullptr;
    }

    // Find all the iterators to the roots in the inorder representation
    RootMap rootLocs;
    for (CIT c = inorder.cbegin(); c != inorder.cend(); ++c) {
      rootLocs[*c] = c;
    }
    // Build a tree using known root locations and the entire two ranges
    // to divide / conquer
    return buildTree({inorder.cbegin(), inorder.cend()},
                     {postorder.cbegin(), postorder.cend()}, rootLocs);
  }
};
} // namespace p0106
