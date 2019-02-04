#include "Common.h"

#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers together!")
#endif // INCLUDED_SOLUTION_HEADER

#if !defined(INCLUDED_SOLUTION_HEADER)
#define INCLUDED_SOLUTION_HEADER "001"

#include <map>
#include <vector>

    class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::map<int, int> H;

    for (int i = 0; i < nums.size(); ++i) {
      auto it = H.find(nums[i]);
      if (it != H.end() && it->second != i) {
        return {it->second, i};
      }
      H[target - nums[i]] = i;
    }
    return {};
  }
};

#endif // INCLUDED_SOLUTION_HEADER