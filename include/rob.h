#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multuple solution headers");
#endif

#define INCLUDED_SOLUTION_HEADER

#include <vector>
#include <iostream>

namespace p0198 {
class Solution {
public:
  int rob(std::vector<int> &nums) {
    size_t n = nums.size();
    // Base case, no houses or an empty house means we aint got mu
    if (n == 0) {
      return 0;
    }
    else if (n == 1) {
      return nums[0];
    }

    std::vector<int> bestAt(nums.size(), 0);
    bestAt[0] = nums[0];
    bestAt[1] = nums[1];
    // Initialize with 0 or nums[0] since paths only begin to diverge after index 2
    // The only way to get to 2: 0, but there are 2 ways to get to 3: 0->3, 1->3
    int delayBy2Max = nums[0];

    // Compute optimal jump costs
    for (size_t i = 2; i <  bestAt.size(); ++i) {
      bestAt[i] = nums[i] + std::max(delayBy2Max, bestAt[i - 2]);
      delayBy2Max = std::max(delayBy2Max, bestAt[i - 2]);
    }

    // The top two paths NEVER end on the same index, one has to end at the last
    // element, and one has to end on the penultimate element (see notes/0198.org)
    return std::max(bestAt[n - 1], bestAt[n - 2]);
  }
};
} // namespace p0198
