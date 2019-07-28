#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers");
#endif

#define INCLUDED_SOLUTION_HEADER

#include <iostream>
#include <string>
#include <vector>

namespace p0647 {
class Solution {
private:
  int countPalindromesCenteredAt(const std::string &str, size_t first,
                                 size_t last) {
    int count = 0;
    while (first < last && str[first] == str[last]) {
      ++count;
      ++last, --first;
      if (last < first) {
        break;
      }
    }
    return count;
  }

public:
  int countSubstrings(std::string s) {
    if (s.size() < 2) {
      return s.size();
    }
    // Trivial case: There are as many size-1 palindromes as there are
    // characters in the string
    size_t count = s.size();
    for (size_t i = 1; i != s.size(); ++i) {
      if (i + 1 != s.size() && s[i - 1] == s[i + 1]) {
        count += countPalindromesCenteredAt(s, i - 1, i + 1);
      }
      if (s[i - 1] == s[i]) {
        count += countPalindromesCenteredAt(s, i - 1, i);
      }
    }

    return count;
  }
};
} // namespace p0647
