#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <cassert>
#include <functional>
#include <iostream>
#include <vector>

namespace p0215 {
class Solution {
  int partition(std::vector<int> &nums, size_t lower, size_t upper,
                size_t pIdx) {
    int pivot = nums[pIdx];
    auto last = lower;
    std::swap(nums[pIdx], nums[upper]);

    for (auto i = lower; i < upper; ++i) {
      if (nums[i] < pivot) {
        std::swap(nums[i], nums[last]);
        ++last;
      }
    }

    // Swap first element of '>' range with the pivot
    std::swap(nums[last], nums[upper]);

    // First elem >= pivot
    return last;
  }

public:
  int findKthLargest(std::vector<int> &nums, int k) {
    size_t target = nums.size() - k;
    size_t lower = 0;
    size_t upper = nums.size() - 1;

    while (lower <= upper) {
      size_t pIdx = lower + (upper - lower + 1) / 2;
      pIdx = partition(nums, lower, upper, pIdx);
      if (target == pIdx) {
        return nums[pIdx];
      } else if (target < pIdx) {
        upper = pIdx - 1;
      } else {
        lower = pIdx + 1;
      }
    }
    assert(false);
    return std::numeric_limits<int>::min();
  }
};
} // namespace p0215
