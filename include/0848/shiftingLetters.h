#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

namespace p0848 {
class Solution {
public:
  std::string shiftingLetters(std::string S, std::vector<int> &shifts) {
    if (S.empty() || S.size() != shifts.size()) {
      return {};
    }
    std::vector<size_t> actualShifts(shifts.begin(), shifts.end());
    constexpr auto BASE = 26;

    std::partial_sum(actualShifts.rbegin(), actualShifts.rend(),
                     actualShifts.rbegin());

    // Now modularize the shifts to the right base before we begin applying them
    std::for_each(actualShifts.begin(), actualShifts.end(),
                  [](size_t &x) { x %= BASE; });

    for (size_t i = 0; i < actualShifts.size(); ++i) {
      S[i] =
          'a' + ((std::move(S[i]) - 'a') + std::move(actualShifts[i])) % BASE;
    }
    return S;
  }
};
} // namespace p0848
