#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers");
#endif

#define INCLUDED_SOLUTION_HEADEAR

#include <vector>
#include <numeric>

namespace p0096 {
class Solution {
public:
  int numTrees(int n) {
    if (n < 2) {
      return 1;
    }
    std::vector<int> count(static_cast<size_t>(n + 1));
    // Base cases
    count[0] = 1;
    count[1] = 1;

    // Iteratively compute the sums
    // Each sum is the dot product of [1..k] with [k..1]
    for (size_t i = 2; i <= n; ++i) {
      count[i] = 0;
      for (size_t j = 0; j < i; ++j) {
        count[i] += count[j] * count[i -  1 - j];
      }
    }

    return count[n];
  }
};
} // namespace p0096
