#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers!");
#endif

#define INCLUDED_SOLUTION_HEADER

#include <iostream>
#include <vector>

namespace p0338 {
class Solution {
public:
  std::vector<int> countBits(int num) {
    if (num == 0) {
      return {0};
    }
    if (num == 1) {
      return {0, 1};
    }

    // `num + 1` slots for counting bits, and we know the first two
    std::vector<int> bitCount(num + 1, 0);
    bitCount[0] = 0;
    bitCount[1] = 1;

    for (size_t i = 2; i < bitCount.size(); ++i) {
      // if n IS EVEN:
      // BITCOUNT[n] = BITCOUNT[k], where n = largestPowerOf2Dividing(n) * k;
      // if n IS ODD:
      // BITCOUNT[n] = BITCOUNT[n - 1] + 1
      if (i % 2 == 0) {
        // We're building up the array, i/2 is bound to exist as an index
        bitCount[i] = bitCount[i / 2];
      } else {
        bitCount[i] = bitCount[i - 1] + 1;
      }
    }
    return bitCount;
  }
};
} // namespace p0338
