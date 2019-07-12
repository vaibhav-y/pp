#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers");
#endif

#define INCLUDED_SOLUTION_HEADER

#include <vector>

namespace p0322 {
class Solution {
public:
  int coinChange(std::vector<int> &coins, int amount) {
    return -1;
  }
};
}
