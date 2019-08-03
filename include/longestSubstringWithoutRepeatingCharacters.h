#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers together
#else

#define INCLUDED_SOLUTION_HEADER

#include <map>
#include <string>

namespace p003 {
class Solution {
private:
  int max(int a, int b) { return a > b ? a : b; }

public:
  int lengthOfLongestSubstring(std::string s) {
    if (s.size() < 2) {
      return s.size();
    }
    int maxLen = 0;
    std::map<char, int> lastIdx;

    for (size_t i = 0, j = 0; j < s.size(); ++j) {
      if (lastIdx.find(s[j]) != std::end(lastIdx)) {
        // Ensure `i` can only move forwards
        i = max(i, lastIdx[s[j]] + 1);
      }
      lastIdx[s[j]] = j;
      maxLen = max(j - i + 1, maxLen);
    }

    return maxLen;
  }
};
} // namespace p003

#endif // INCLUDED_SOLUTION_HEADER
