#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers");
#endif

#define INCLUDED_SOLUTION_HEADER

#include <algorithm>
#include <limits>
#include <vector>

namespace p0322 {
class Solution {
public:
  int coinChange(std::vector<int> &coins, int amount) {
    if (coins.empty()) {
      return -1;
    }

    const size_t &DEFAULT = std::numeric_limits<int>::max();
    std::vector<size_t> change(static_cast<size_t>(amount) + 1, DEFAULT);
    // Base case
    change[0] = 0;
    const int &leastDenomination =
        *std::min_element(coins.begin(), coins.end());
    for (size_t i = leastDenomination; i < change.size(); ++i) {
      for (size_t j = 0; j < coins.size(); ++j) {
        if (i >= coins[j]) {
          change[i] = std::min(change[i], 1 + change[i - coins[j]]);
        }
      }
    }
    return (change.back() == DEFAULT) ? -1 : change.back();
  }
};
} // namespace p0322
