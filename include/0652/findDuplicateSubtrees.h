#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <TreeNode.h>
#include <vector>
#include <unordered_map>

namespace p0652 {
class Solution {
  std::string hashTree(TreeNode *root,
                       std::unordered_map<std::string, int> &count,
                       std::vector<TreeNode *> &duplicates) {
    if (!root) {
      return {};
    }
    std::stringstream ss;
    ss << hashTree(root->left, count, duplicates) << ",";
    ss << hashTree(root->right, count, duplicates) << ",";
    ss << std::to_string(root->val);
    
    const std::string &&T(ss.str());
    auto it = count.find(T);
    if (it == count.end()) {
      count[T] = 1;
    } else {
      ++it->second;
      if (it->second == 2) {
        duplicates.push_back(root);
      }
    }
    return T;
  }
public:
  std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    std::unordered_map<std::string, int> hashes;
    std::vector<TreeNode *> duplicates;
    hashTree(root, hashes, duplicates);
    return duplicates;
  }
};
} // namespace p0652
