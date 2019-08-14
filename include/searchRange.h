#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <vector>

namespace p0034 {
class Solution {
public:
  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    if (nums.empty()) {
      return {-1, -1};
    }
    return {};
  }
};
} // namespace p0034
