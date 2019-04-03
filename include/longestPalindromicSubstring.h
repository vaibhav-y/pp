#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers together!")
#else
#define INCLUDED_SOLUTION_HEADER "005"

#include <string>
#include <vector>

#include "Common.h"

namespace p005 {
class Solution {
private:
  using position_t = std::pair<int, int>;

  bool isPalindrome(std::string &s) {
    bool palindromic = true;
    auto cit = s.cbegin();
    auto crit = s.crbegin();
    for (; cit != s.cend() && crit != s.crend(); ++cit, ++crit) {
      palindromic &= ((*cit) == (*crit));
    }
    return palindromic;
  }

  // Compute the manhattan distance
  inline size_t mdist(position_t start, position_t end) {
    return abs(start.first - end.first) + abs(start.second - end.second);
  }

public:
  std::string longestPalindrome(std::string s) {
    size_t length = s.size();
    if (length < 2 || isPalindrome(s)) {
      return s;
    }

    std::vector<std::vector<short>> in_palindrome{
        length, std::vector<short>(length, 0)};

    for (size_t i = 0, len = length; i < length; ++i) {
      for (size_t j = 0; j < length; ++j) {
        if (s[len - 1 - i] == s[j]) {
          in_palindrome[i][j] = 1;
        }
      }
    }

    std::pair<size_t, size_t> best_start{0, 0};
    std::pair<size_t, size_t> best_end{0, 0};

    // Only look for length 2 and above since we find length 1 by default
    for (size_t i = 0; i < length - 1; ++i) {
      for (size_t j = 0; j < length - 1; ++j) {
        // Start counting down right
        if (in_palindrome[i][j]) {
          std::pair<size_t, size_t> end{i, j};
          while (end.first < length - 1 && end.second < length - 1 &&
                 in_palindrome[end.first + 1][end.second + 1]) {
            ++end.first;
            ++end.second;
            // Never visit this chain again
            in_palindrome[end.first][end.second] = 0;
          }
          if (mdist(best_start, best_end) < mdist({i, j}, end)) {
            best_start = {i, j};
            best_end = end;
          }
        }
      }
    }

    // Match occurred in lower triangular part
    if (best_start.second < best_end.second) {
      return s.substr(best_start.second,
                      best_end.second - best_start.second + 1);
    }
    return s.substr(best_start.first, best_end.first - best_start.first + 1);
  }
};
} // namespace p005

#endif // INCLUDED_SOLUTION_HEADER
