#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers");
#endif

#define INCLUDED_SOLUTION_HEADER

#include <vector>
#include <limits>

namespace p0334 {
class Solution {
public:
  bool increasingTriplet(std::vector<int> &nums) {
    if (nums.size() < 3) {
      return false;
    }

    int first = std::numeric_limits<int>::max();
    int second = std::numeric_limits<int>::max();

    for (auto n : nums) {
      if (n <= first) {
        first = n;
      } else if (n <= second) {
        second = n;
      } else {
        return true;
      }
    }
    return false;
  }
};
} // namespace p0334
