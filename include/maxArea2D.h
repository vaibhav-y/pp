#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#else

#define INCLUDED_SOLUTION_HEADER

#include <vector>

namespace p011 {
class Solution {
public:
  int maxArea(std::vector<int> &height) {
    if (height.empty()) {
      return 0;
    }

    int i = 0, j = height.size() - 1;
    int maximum = 0;
    while (i < j) {
      maximum = std::max(maximum, std::min(height[j], height[i]) * (j - i));
      if (height[i] < height[j]) {
        ++i;
      } else {
        --j;
      }
    }
    return maximum;
  }
};
} // namespace p011

#endif
