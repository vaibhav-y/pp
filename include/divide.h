#if defined(INCLUDED_SOLUTION_HEADER)
#error Wont include multiple solution headers
#endif

#include <limits>
#include <cmath>
#include <iostream>

namespace p0029 {
class Solution {
public:
  // The code below is intentionally awful becuase the 'challenge' was to not
  // use the multiplication, division or modulus operators
  int divide(int dividend, int divisor) {
    if (divisor == 0) {
      return std::numeric_limits<int>::max();
    } else if (divisor == 1) {
      return dividend;
    } else if (divisor == -1 && dividend == std::numeric_limits<int>::min()) {
      return std::numeric_limits<int>::max();
    } else if (dividend == divisor) {
      return 1;
    }
    int sign = dividend < 0 ? -1 : 1;
    sign = divisor < 0 ? -sign : sign;

    // These are still the same width as the signed integer, and should work
    // on that very same machine. if there isn't support for unsigned numbers
    // then I don't know what is even happening...
    unsigned int quotient = 0;
    unsigned int remainder = dividend < 0 ? -((unsigned int) dividend) : dividend;

    // Make binary strides upward while there is no remainder left to divide up
    while (true) {
      unsigned int product = divisor < 0 ? -((unsigned int)divisor) : divisor;
      unsigned int roundQuotient = 1;
      if (remainder < product) {
        break;
      }
      while ((product << 1) < remainder) {
        product = product << 1;
        roundQuotient <<= 1;

        // Break if it can overflow in the next comparison
        // This is equivalent to checking if
        // product > (1 << 30), i.e check if bit 30 is set
        // meaning that one more right shift would yield something
        // larger than 2**31 - 1
        if (product >> 30) {
          break;
        }
      }
      remainder -= product;
      quotient += roundQuotient;
    }
    return sign * ((int) quotient);
  }
};
} // namespace p0029
