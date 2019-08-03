#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers together
#else

#define INCLUDED_SOLUTION_HEADER

#include <iostream>
#include <string>
#include <vector>

#include "Common.h"

namespace p005 {
class Solution {
private:
  inline std::string grow(const std::string &src, size_t begin, size_t end) {
    while (begin >= 1 && end + 1 < src.size() &&
           src[begin - 1] == src[end + 1]) {
      ++end;
      --begin;
    }
    return src.substr(begin, end - begin + 1);
  }

public:
  std::string longestPalindrome(std::string s) {
    if (s.size() < 2) {
      return s;
    }

    std::string longest{s[0]};
    for (size_t c = 0; c < s.size() - 1; ++c) {
      std::string temp{grow(s, c, c)};
      longest = temp.size() > longest.size() ? temp : longest;
      // Only grow even length ones if we found a palindromic center:
      if (s[c] == s[c + 1]) {
        temp = grow(s, c, c + 1);
        longest = temp.size() > longest.size() ? temp : longest;
      }
    }

    return longest;
  }
};
} // namespace p005

#endif // INCLUDED_SOLUTION_HEADER
