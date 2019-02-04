#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers together!")
#endif // INCLUDED_SOLUTION_HEADER

#if !defined(INCLUDED_SOLUTION_HEADER)
#define INCLUDED_SOLUTION_HEADER "003"

#include <map>
#include <string>

    class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {}
};

#endif // INCLUDED_SOLUTION_HEADER