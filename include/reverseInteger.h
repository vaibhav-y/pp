#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers!");
#else

#include <cmath>
#include <limits>

namespace p007 {
class Solution {
private:
  inline bool checkOverflow_(int quotient, int rem) const {
    if (quotient == 0) {
      return false;
    }
    const int &MAX = std::numeric_limits<int>::max();
    const int &MIN = std::numeric_limits<int>::min();

    if (quotient > 0) {
      return quotient > ((MAX - rem) / 10);
    }
    return quotient < (MIN - rem) / 10;
  }

public:
  /*  */
  int reverse(int x) {
    // This function could be simplified using a broader type for the integer
    // but I haven't because that is against the spirit of pre-emptive
    // overflow checking, which is probably the most important part of this
    // question
    if (x == 0) {
      return x;
    }
    int reversed = 0;

    while (x != 0) {
      if (checkOverflow_(reversed, x % 10)) {
        return 0;
      }
      reversed = reversed * 10 + x % 10;
      x /= 10;
    }
    return reversed;
  }
};
} // namespace p007
#endif
