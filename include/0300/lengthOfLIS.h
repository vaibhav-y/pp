#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

#include <limits>
#include <vector>

namespace p0300 {
class Solution {
public:
  int lengthOfLIS(std::vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }

    std::vector<int> optimalLength(nums.size(), 1);

    // Only 1 subsequence that starts at the last element
    optimalLength.back() = 1;
    int largest = 1;

    // Work our way upwards to fill out the length of the longest increasing
    // subsequence starting at index i
    for (int i = optimalLength.size() - 2; i >= 0; --i) {
      // L[i] = 1 + max(L[j]), where j > i and nums[j] >= nums[i]
      for (size_t j = i + 1; j < optimalLength.size(); ++j) {
        if (nums[j] > nums[i]) {
          optimalLength[i] = std::max(optimalLength[i], 1 + optimalLength[j]);
        }
      }
      largest = std::max(largest, optimalLength[i]);
    }
    return largest;
  }
};
} // namespace p0300
