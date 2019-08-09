#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

namespace p0044 {
class Solution {
private:
  // Return the minimum length of string that is required by the pattern
  inline size_t minLength(const std::string &pattern) {
    size_t n = 0;
    for (auto &ch_ : pattern) {
      if (ch_ != '*') {
        ++n;
      }
    }
    return n;
  }

public:
  bool isMatch(std::string input, std::string pattern) {
    if (pattern.empty()) {
      return input.empty();
    }
    if (input.length() < minLength(pattern)) {
      return false;
    }
    // construct the suffix array for this input string
    std::vector<size_t> suffixes(input.size());
    for (size_t i = 0; i < suffixes.size(); ++i) {
      suffixes[i] = i;
    }

    // Build a suffix array
    std::sort(suffixes.begin(), suffixes.end(),
              [&, input](const int &a, const int &b) {
                return input.substr(a) < input.substr(b);
              });

    size_t currentIndex = 0;

  }
};
} // namespace p0044
