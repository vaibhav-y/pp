#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers together!")
#else
#define INCLUDED_SOLUTION_HEADER "005"

#include <iostream>
#include <string>
#include <vector>

#include "Common.h"

namespace p005 {
class Solution {
private:
  inline bool isPalindrome(const std::string &s) const {
    auto cit = s.cbegin();
    auto crit = s.crbegin();

    while (*crit == *cit && cit != s.cend()) {
      ++cit;
      ++crit;
    }

    return cit == s.cend();
  }

public:
  std::string longestPalindrome(std::string s) {
    size_t length = s.size();
    if (length < 2) {
      return s;
    }

    // Scan string for palindromes of various lengths
    for (size_t len = length; len != 0; --len) {
      for (size_t start = 0; start + len - 1 < length; ++start) {
        auto substring = s.substr(start, len);
        if (isPalindrome(substring)) {
          return substring;
        }
      }
    }

    // UNREACHABLE
    return {};
  }
};
} // namespace p005

#endif // INCLUDED_SOLUTION_HEADER
