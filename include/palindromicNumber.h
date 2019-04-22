#if defined(INCLUDED_SOLUTION_HEADER)
static_assert(false, "Won't include multiple solution headers");
#else

namespace p009 {
class Solution {
public:
  bool isPalindrome(int x) {
    if (x == 0) {
      return true;
    } else if (x < 0 || x % 10 == 0) {
      return false;
    }
    int reversed = 0;

    while (x > reversed) {
      reversed = 10 * reversed + x % 10;
      x /= 10;
    }

    return (reversed == x) || (reversed / 10 == x);
  }
};
} // namespace p009

#endif
