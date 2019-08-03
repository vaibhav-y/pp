#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers together
#else

#define INCLUDED_SOLUTION_HEADER "001"

#include "Common.h"

#include <map>
#include <vector>

namespace p001 {
class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::map<int, int> H;

    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
      auto it = H.find(nums[i]);
      if (it != H.end() && it->second != i) {
        return {it->second, i};
      }
      H[target - nums[i]] = i;
    }
    return {};
  }
};
} // namespace p001

#endif // INCLUDED_SOLUTION_HEADER
