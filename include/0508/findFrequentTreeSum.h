#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solutio headers
#endif

#include <algorithm>
#include <map>
#include <vector>

#include <TreeNode.h>

namespace p0508 {
class Solution {
private:
  void collectSubtreeSumFrequencies(TreeNode *root, int &acc,
                                    std::map<int, int> &freqs) {
    int left = acc;
    int right = acc;

    if (root->left) {
      collectSubtreeSumFrequencies(root->left, left, freqs);
    }
    if (root->right) {
      collectSubtreeSumFrequencies(root->right, right, freqs);
    }

    // Update accumulator with value for this node
    acc = root->val + left + right;
    auto it = freqs.find(acc);
    if (it == freqs.end()) {
      freqs.insert({acc, 1});
    } else {
      ++it->second;
    }
  }

public:
  std::vector<int> findFrequentTreeSum(TreeNode *root) {
    if (!root) {
      return {};
    }
    int acc = 0;
    std::map<int, int> freqs;
    collectSubtreeSumFrequencies(root, acc, freqs);
    std::vector<std::pair<int, int>> freqToSum(
        std::make_move_iterator(freqs.begin()),
        std::make_move_iterator(freqs.end()));
    std::sort(freqToSum.begin(), freqToSum.end(),
              [](auto l, auto r) { return l.second > r.second; });

    auto it = freqToSum.begin();
    int maxFreq = it->second;
    std::vector<int> result;
    while (it != freqToSum.end() && it->second == maxFreq) {
      result.push_back(it->first);
      ++it;
    }
    return result;
  }
};
} // namespace p0508
