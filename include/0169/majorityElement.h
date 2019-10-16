#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <vector>
#include <cassert>

namespace p0169 {
class Solution {
public:
  int majorityElement(std::vector<int>& nums) {
    assert(!nums.empty());

    int elem = nums[0];
    int count = 0;
    for (const auto &n: nums) {
      if (elem == n) {
        ++count;
      } else {
        --count;
        if (count < 0) {
          elem = n;
          count = 1;
        }
      }
    }
    return elem;
  }
};
}
