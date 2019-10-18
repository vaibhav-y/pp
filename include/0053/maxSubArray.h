#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <limits>
#include <vector>

namespace p0053 {
class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    int runningMax = nums[0];
    int overallMax = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
      if (runningMax + nums[i] >= nums[i]) {
        // Either you accumulate this index to expand the current array
        runningMax += nums[i];
      } else {
        // Or start afresh with this index as the first element
        runningMax = nums[i];
      }
      overallMax = std::max(runningMax, overallMax);
    }
    return overallMax;
  }
};
} // namespace p0053
