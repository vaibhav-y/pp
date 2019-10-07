#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <TreeNode.h>
#include <vector>
#include <deque>

namespace p0199 {
class Solution {
public:
  std::vector<int> rightSideView(TreeNode* root) {
    if (!root) {
      return {};
    }
    std::vector<int> view;
    std::deque<TreeNode *> parentQ, childQ;
    parentQ.push_back(root);

    while (!parentQ.empty()) {
      // This is the right-most element in this horizontal level
      view.push_back(parentQ.back()->val);
      while(!parentQ.empty()) {
        TreeNode *current = parentQ.front();
        parentQ.pop_front();
        if (current->left) {
          childQ.push_back(current->left);
        }
        if (current->right) {
          childQ.push_back(current->right);
        }
      }
      parentQ.swap(childQ);
    }
    return view;
  }
};
}
