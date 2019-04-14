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
  inline std::string grow(std::string src, size_t begin, size_t end) {
    while (begin >= 0 && end < src.size() && src[begin] == src[end]) {
      --begin;
      ++end;
    }
    return src.substr(begin + 1, end - begin + 1);
  }

public:
  std::string longestPalindrome(std::string s) {
    if (s.size() < 2) {
      return s;
    }

    std::string longest{s[0]};
    for (size_t c = 0; c < s.size(); ++c) {
      std::string temp{grow(s, c, c)};
      longest = temp.size() > longest.size() ? temp : longest;
      temp = grow(s, c, c + 1);
      longest = temp.size() > longest.size() ? temp : longest;
    }

    return longest;
  }
};
} // namespace p005

#endif // INCLUDED_SOLUTION_HEADER
