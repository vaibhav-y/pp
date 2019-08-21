#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <vector>
#include <iostream>
namespace p0034 {
class Solution {
private:
  int lowerBound(std::vector<int> &nums, int target) {
  }


  int upperBound(std::vector<int> &nums, int target) {
  }
public:
  std::vector<int> searchRange(std::vector<int> &nums, int target) {
    return {lowerBound(nums, target), upperBound(nums, target)};
  }
};
} // namespace p0034
