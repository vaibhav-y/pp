#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#define INCLUDED_SOLUTION_HEADER

namespace p070 {
class Solution {
public:
  int climbStairs(int n) {
    if (n < 2) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }
    int current = 2;
    int back_1 = 1;
    while (n > 2) {
      int temp = current + back_1;
      back_1 = current;
      current = temp;
      --n;
    }
    return current;
  }
};
} // namespace p070
