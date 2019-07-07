#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers");
#endif

#define INCLUDED_SOLUTION_HEADER

#include <vector>

namespace p0121 {
class Solution {
public:
  int maxProfit(std::vector<int> &prices) {
    if (prices.size() < 2) {
      return 0;
    } else if (prices.size() == 2) {
      return std::max(0, prices[1] - prices[0]);
    }

    int maximumProfit = 0;
    int leastSoFar = prices[0];
    for (size_t i = 1; i < prices.size(); ++i) {
      leastSoFar = std::min(leastSoFar, prices[i]);
      maximumProfit = std::max(maximumProfit, prices[i] - leastSoFar);
    }

    return maximumProfit;
  }
};
} // namespace p0121
