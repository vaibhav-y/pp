#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers together
#else

#define INCLUDED_SOLUTION_HEADER

#include <limits>
#include <vector>

namespace p004 {
class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    size_t s1 = nums1.size();
    size_t s2 = nums2.size();
    size_t count = s1 + s2;
    double median = std::numeric_limits<double>::min();

    size_t i = 0, j = 0;
    double curr = std::numeric_limits<int>::max();
    double prev = std::numeric_limits<int>::max();

    while (i < s1 || j < s2) {
      int n1 = i == s1 ? std::numeric_limits<int>::max() : nums1[i];
      int n2 = j == s2 ? std::numeric_limits<int>::max() : nums2[j];

      prev = curr;
      if (n1 <= n2) {
        curr = n1;
        ++i;
      } else {
        curr = n2;
        ++j;
      }

      if (i + j - 1 == count / 2) {
        if (count % 2 == 0) {
          median = (prev + curr) / 2;
        } else {
          median = curr;
        }
        break;
      }
    }
    return median;
  }
};
} // namespace p004

#endif // INCLUDED_SOLUTION_HEADER
