#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include mulitple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <string>
#include <vector>

namespace p0916 {
class Solution {
public:
  std::vector<std::string> wordSubsets(std::vector<std::string> &A,
                                       std::vector<std::string> &B) {
    std::vector<std::string> matches;
    matches.reserve(A.size());
    std::vector<int> bCharCount(26, 0);

    for (auto &b : B) {
      std::vector<int> temp(26, 0);
      for (auto &ch_ : b) {
        ++temp[ch_ - 'a'];
      }
      for (size_t i = 0; i < 26; ++i) {
        bCharCount[i] = std::max(bCharCount[i], temp[i]);
      }
    }

    for (auto &a : A) {
      std::vector<int> temp(bCharCount);
      for (auto &ch_ : a) {
        if (bCharCount[ch_ - 'a'] > 0) {
          --bCharCount[ch_ - 'a'];
        }
      }
      bool universal = true;
      for (auto &i : bCharCount) {
        if (i != 0) {
          universal = false;
          break;
        }
      }
      if (universal) {
        matches.push_back(a);
      }
      bCharCount.swap(temp);
    }

    return matches;
  }
};
} // namespace p0916
