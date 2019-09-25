#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <vector>

namespace p0746 {
class Solution {
public:
  int minCostClimbingStairs(std::vector<int> &cost) {
    size_t n = cost.size();
    std::vector<int> minCost(cost);

    for (size_t i = 2; i < cost.size(); ++i) {
      minCost[i] += std::min(minCost[i - 1], minCost[i - 2]);
    }

    return std::min(minCost[n - 1], minCost[n - 2]);
  }
};
} // namespace p0746
